# Set the cmake version or higher
cmake_minimum_required(VERSION 3.10)

# Project name
project(MovieSelectorApp)

# Set standard C++20
set(CMAKE_CXX_STANDARD 20)

# Treat warnings as errors?
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

# Add "include/" to the header search path
include_directories(include)

# Source files:
add_executable(MovieSelectorApp
    src/main.cpp
    src/DataHandler.cpp
    src/Questionaire.cpp
)
