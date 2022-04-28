cmake_minimum_required(VERSION 3.22)

project(rubics_cube_solver)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tests)

add_executable(rubics_cube_solver main.cpp Cube.cpp Cube.h)
