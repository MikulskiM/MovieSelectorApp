# Set the cmake version or higher
cmake_minimum_required(VERSION 3.10)

# Project name
project(MovieSelectorApp)

# Set standard C++20
set(CMAKE_CXX_STANDARD 20)

# Treat warnings as errors?
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

# Source files:
add_executable(MovieSelectorApp
    main.cpp
    DataHandler.cpp
)
