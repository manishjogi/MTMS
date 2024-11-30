cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ModularTaskManagementSystem VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define paths for source files and header files
include_directories(${CMAKE_SOURCE_DIR}/headers)
file(GLOB SOURCES ${CMAKE_SOURCE_DIR}/sources/*.cpp)

# Add main.cpp explicitly
set(SOURCES ${SOURCES} ${CMAKE_SOURCE_DIR}/main.cpp)

# Create the executable
add_executable(MTMS ${SOURCES})

# Enable warnings during compilation
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(MTMS PRIVATE -Wall -Wextra -Wpedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(MTMS PRIVATE /W4)

endif()
