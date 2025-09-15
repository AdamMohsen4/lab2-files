#!/bin/bash

# Check if filename is provided
if [ $# -eq 0 ]; then
    echo "Usage: ./run.sh <filename_without_extension>"
    echo "Example: ./run.sh print-primes"
    exit 1
fi

filename=$1

echo "Compiling $filename.c..."
gcc "$filename.c" -o "$filename"

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running $filename..."
    echo "----------------------------------------"
    ./"$filename" "${@:2}"  # Pass any additional arguments to the program
else
    echo "Compilation failed!"
    exit 1
fi
