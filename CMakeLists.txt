# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and language
project(FlowSimulator VERSION 1.0 LANGUAGES CXX)

# Require C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add include directory
include_directories(include)

# Collect all source files
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(FlowSimulator ${SOURCES})
# add_executable(FlowSimulator main.cpp)
