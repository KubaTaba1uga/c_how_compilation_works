#!/bin/bash

# Ścieżka do katalogu re
DIR="re"

# Sprawdzenie, czy katalog re istnieje
if [ -d "$DIR" ]; then
  echo "Directory $DIR exists. Proceeding with CMake build and install."

  cd $DIR
  
  # Konfiguracja za pomocą CMake
  cmake -B build || { echo "CMake configuration failed"; exit 1; }

  # Budowanie z użyciem CMake z równoległym procesowaniem
  cmake --build build -j || { echo "Build failed"; exit 1; }

  # Instalowanie za pomocą CMake (wymaga sudo)
  sudo cmake --install build || { echo "Installation failed"; exit 1; }

  # Zaktualizowanie cache biblioteki dynamicznej
  sudo ldconfig || { echo "ldconfig failed"; exit 1; }

else
  echo "Error: Directory $DIR does not exist."
  exit 1
fi
