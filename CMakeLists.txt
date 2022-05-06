cmake_minimum_required(VERSION 3.20)

project(rubics_cube_solver)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tests)

add_executable(rubics_cube_solver main.cpp src/Cube.cpp src/Cube.h)
