#!/bin/bash

# set -euo pipefail  # Exit on error, unset variable, or failure in any part of a pipeline

# Ścieżka do katalogu baresip
DIR="baresip"

# Source dir
SRC_DIR="example_1_no_c_include"

disable_tests() {
  # Input file provided as a function argument
  local input_file="$1"
  local temp_file=$(mktemp)

  # Read the input file line by line and store the modified content in a temp file
  while IFS= read -r line; do
    # Check if the line contains "TEST" with "call" and is not already commented
    if echo "$line" | grep -q "TEST(.*call.*)" && ! echo "$line" | grep -q "^\s*\/\*"; then
      # If the line contains "call" and is not commented, comment it out
      echo "    /* $line */" >> "$temp_file"
    else
      # Write other lines unchanged
      echo "$line" >> "$temp_file"
    fi
  done < "$input_file"

  # Replace the original file with the modified content
  mv "$temp_file" "$input_file"

  echo "File modification complete. The changes have been made in $input_file"
}

insert_test() {
  # Input file for the test array (tests/main.c)
  local input_file="$1"
  # Name of the test to insert
  local test_name="$2"
  local test_source="${test_name}.c"
  
  # Check if the test is already present in the input file
  if grep -q "TEST($test_name)," "$input_file"; then
    echo "Test '$test_name' already exists in $input_file, skipping insertion."
    return
  fi

  # Get the directory of the input file
  local dir=$(dirname "$input_file")

  # Search for CMakeLists.txt in the input file's directory or parent directories
  local cmake_file
  cmake_file=$(find "$dir" -type f -name "CMakeLists.txt" | head -n 1)

  if [ -z "$cmake_file" ]; then
    echo "Error: CMakeLists.txt not found"
    exit 1
  fi

  local temp_file=$(mktemp)

  # --- Modify tests/main.c ---
  # Flag to detect if we are inside the array
  inside_array=false

  # Read the input file line by line and store the modified content in a temp file
  while IFS= read -r line; do
    # Detect the start of the test array
    if [[ "$line" =~ "static const struct test tests" ]]; then
      inside_array=true
    fi

    # If we are inside the array, look for the closing bracket '};' to insert before it
    if $inside_array && [[ "$line" == "};" ]]; then
      # Insert the new test line just before the closing bracket
      echo "    TEST($test_name)," >> "$temp_file"
      inside_array=false
    fi

    # Write the current line to the temp file
    echo "$line" >> "$temp_file"
  done < "$input_file"

  # Replace the original file with the modified content
  mv "$temp_file" "$input_file"

  echo "Test insertion complete. '$test_name' has been added to the array in $input_file"

  # --- Modify CMakeLists.txt ---
  temp_file=$(mktemp)

  # Flag to detect where to insert the new source file
  inside_add_executable=false

  # Read the CMakeLists.txt line by line
  while IFS= read -r line; do
    # Detect the start of the add_executable block
    if [[ "$line" =~ "add_executable(" ]]; then
      inside_add_executable=true
    fi

    # If we're inside the add_executable block, look for the closing parenthesis
    if $inside_add_executable && [[ "$line" == ")" ]]; then
      # Insert the new test source file before the closing parenthesis
      echo "  $test_source" >> "$temp_file"
      inside_add_executable=false
    fi

    # Write the current line to the temp file
    echo "$line" >> "$temp_file"
  done < "$cmake_file"

  # Replace the original CMakeLists.txt with the modified content
  mv "$temp_file" "$cmake_file"

  cp -f ../$SRC_DIR/$test_source test/

  echo "Source file insertion complete. '$test_source' has been added to $cmake_file"
}

insert_line_if_not_exists() {
  local file="$1"    # The file to check and possibly modify
  local line="$2"    # The line to check and insert

  # Check if the line exists in the file
  grep -qxF "$line" "$file"

  # If the line doesn't exist, append it to the file
  if [ $? -ne 0 ]; then
    echo "$line" >> "$file"
    echo "Line inserted: $line"
  else
    echo "Line already exists in the file: $line"
  fi
}

# Sprawdzenie, czy katalog baresip istnieje
if [ -d "$DIR" ]; then
  echo "Directory $DIR exists. Proceeding with CMake build and install."

  cd $DIR

  disable_tests test/main.c
  insert_test test/main.c test_dummy_and_caller
  insert_line_if_not_exists "test/test.h" "int test_dummy_and_caller(void);"
  cp -fr ../$SRC_DIR/dummy_module/ ./modules/dummy_module
  cp -fr ../$SRC_DIR/caller_module/ ./modules/caller_module
  
  # Konfiguracja za pomocą CMake
  cmake -B build -DEXTRA_MODULES="dummy_module;caller_module" || { echo "CMake configuration failed"; exit 1; }

  # Budowanie z użyciem CMake z równoległym procesowaniem
  cmake --build build -j 1 || { echo "Build failed"; exit 1; }

else
  echo "Error: Directory $DIR does not exist."
  exit 1
fi
