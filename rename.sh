#!/bin/bash

# Loop through all files in the current directory
for file in *; do
  # Check if it's a file and not a directory
  if [ -f "$file" ]; then
    # Get the base name without the extension
    base_name=$(basename "$file" .c)
    
    # Rename the file by appending _bonus.c to the base name
    mv "$file" "${base_name}_bonus.c"
  fi
done

echo "Files have been renamed!"
