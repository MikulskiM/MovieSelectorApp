cmake_minimum_required(VERSION 3.10)  # Set the cmake version or higher
project(MovieSelectorApp)  # Project name

set(CMAKE_CXX_STANDARD 20)  # Set standard C++20

# Treat warnings as errors?
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

# Source files:
add_executable(FilmSelectorApp main.cpp)
