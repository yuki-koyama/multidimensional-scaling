cmake_minimum_required(VERSION 3.1)
enable_testing()

project(multidimensional-scaling)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(simple-test)

add_test(NAME simple-test COMMAND $<TARGET_FILE:simple-test>)
