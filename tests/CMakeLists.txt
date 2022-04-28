cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)

project(Google_tests)

add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test_cube.cpp ../Cube.cpp ../Cube.h)
target_link_libraries(Google_Tests_run gtest gtest_main)
