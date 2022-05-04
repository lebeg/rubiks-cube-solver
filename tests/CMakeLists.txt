cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 23)

project(Google_tests)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty/googletest ${CMAKE_CURRENT_BINARY_DIR}/googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(Google_Tests_run test_cube.cpp ../src/Cube.cpp ../src/Cube.h)
target_link_libraries(Google_Tests_run gtest gtest_main)
