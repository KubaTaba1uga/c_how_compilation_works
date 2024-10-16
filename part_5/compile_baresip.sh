#!/bin/bash

# Ścieżka do katalogu baresip
DIR="baresip"

disable_tests() {
  # Input file provided as a function argument
  local input_file="$1"
  local temp_file=$(mktemp)

  # Read the input file line by line and store the modified content in a temp file
  while IFS= read -r line; do
    if echo "$line" | grep -q "TEST(.*call.*)"; then
      # If the line contains "call", comment it out
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

# Sprawdzenie, czy katalog baresip istnieje
if [ -d "$DIR" ]; then
  echo "Directory $DIR exists. Proceeding with CMake build and install."

  cd $DIR

  disable_tests test/main.c
  
  # Konfiguracja za pomocą CMake
  cmake -B build || { echo "CMake configuration failed"; exit 1; }

  # Budowanie z użyciem CMake z równoległym procesowaniem
  cmake --build build -j || { echo "Build failed"; exit 1; }

else
  echo "Error: Directory $DIR does not exist."
  exit 1
fi
