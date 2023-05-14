#!/bin/bash

# Define the symbols to check
CHANGES=$(git diff --name-only HEAD~1 HEAD)
# Iterate over each modified file
for file in $CHANGES; do
  filename=$(basename "$file")
  extension="${filename##*.}"
  if [[ "$extension" == "sv" ]]; then
    # Read each line of the file
    while IFS= read -r line; do
        # Check lines starting with 'input'
        if [[ $line == input* && $line != *"_i"* ]]; then
            echo "Error: Line in $file starting with 'input' does not end with *_i*: $line"
            error_flag=1
        fi

        # Check lines starting with 'output'
        if [[ $line == output* && $line != *"_o"* ]]; then
            echo "Error: Line in $file starting with 'output' does not end with *_o*: $line"
            error_flag=1
        fi
    done < "$file"
  fi
done

# Display result
if [[ $error_flag -eq 0 ]]; then
    echo "No errors found in the last commit."
else
    echo "Errors found in the last commit."
fi
