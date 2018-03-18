cmake_minimum_required(VERSION 3.1)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})
include_directories(${CMAKE_SOURCE_DIR})

add_executable(simple-test test.cpp)
target_link_libraries(simple-test)
