#!/bin/bash

# Check if CMake is installed
if ! command -v cmake &> /dev/null
then
    echo "CMake could not be found. Please install CMake and try again."
    exit 1
fi

# Check if g++ is installed
if ! command -v g++ &> /dev/null
then
    echo "g++ could not be found. Please install g++ and try again."
    exit 1
fi

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

# Change to the build directory
cd build

# Run CMake to generate the Makefile
echo "Running CMake..."
cmake ..

# Build the project
echo "Building the project..."
make

# Check if the build was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful."
    echo "Running the program..."
    ./FilmSelectorApp
else
    echo "Compilation failed."
fi