#!/bin/bash

# Define the symbols to check
SYMBOLS=("=" "&" "+" "|" "^")
CHANGES=$(git diff --name-only HEAD~1 HEAD)
# Run the script on all relevant files
for file in $CHANGES; do
  filename=$(basename "$file")
  extension="${filename##*.}"
  if [[ "$extension" == "sv" ]]; then
    # Check for spaces around symbols in the file
    for symbol in "${SYMBOLS[@]}"; do
      # Check for the pattern "<symbol> " or " <symbol>"
      if grep -n -E "\\$symbol[[:space:]]|\\s$symbol" "$file"; then
        echo "Error: Found space around $symbol in file $file"
        exit 1
      fi
    done
  fi
done
