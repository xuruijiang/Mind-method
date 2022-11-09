#include_directories(SYSTEM "/foo/bar")

cmake_minimum_required(VERSION 3.21)
project(test_08_12 C)

set(CMAKE_C_STANDARD 99)

add_executable(test_08_12 test.c)
