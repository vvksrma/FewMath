cmake_minimum_required(VERSION 3.10)
project(FewMath)

set(CMAKE_CXX_STANDARD 17)

# Global include directory
set(FEW_MATH_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/src/core/include)
include_directories(${FEW_MATH_INCLUDE_DIR})

# Core Library
add_library(fewmath STATIC
    src/core/algebra.cpp
)

# Test executable
add_executable(test_gcd tests/test_gcd.cpp)

# Link library to test
target_link_libraries(test_gcd fewmath)
