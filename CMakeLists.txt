cmake_minimum_required(VERSION 3.28)
project(TheGameOfLife LANGUAGES CXX)

# Setting up CMake variables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(src)