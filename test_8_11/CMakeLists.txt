#include_directories(SYSTEM "/foo/bar")
cmake_minimum_required(VERSION 3.21)
project(test_8_11 C)

set(CMAKE_C_STANDARD 99)

add_executable(test_8_11 test.c)

