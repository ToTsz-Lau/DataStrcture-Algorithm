# Minimum required version of CMake
cmake_minimum_required(VERSION 3.10)

# Name of the project
project(MySimpleProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)  # Use 11, 14, 17, or any other standard you need

# Add an executable target for the main program
add_executable(MySimpleExecutable main.cpp)

