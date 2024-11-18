#!/bin/bash
  
# Check if a filename is provided
if [ -z "$1" ]; then
  echo "Usage: $0 filename.cpp"
  exit 1
fi

# Extract the base name without extension
filename=$(basename -- "$1")
filename="${filename%.*}"

# Compile the C++ file
g++ "$1" -o "$filename.exe"

echo "Running your cpp file"
# Check if the compilation was successful
if [ $? -eq 0 ]; then
  # Run the executable
  ./"$filename.exe"
  echo "
Time to remove the file!"

else
  echo "Compilation failed."
fi