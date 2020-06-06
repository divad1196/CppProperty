cmake_minimum_required(VERSION 3.15)
# project(CppProperty)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wconversion -Wall -Wextra -pedantic -std=c++11")


add_executable(
    tests
    tests.cpp
)