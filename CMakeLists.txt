cmake_minimum_required(VERSION 3.20)

project(rubics_cube_solver)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(tests)

add_executable(rubics_cube_solver main.cpp src/Cube.cpp src/Cube.h src/Render.cpp src/Render.h)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(rubics_cube_solver ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})
target_compile_options(rubics_cube_solver PRIVATE -Wno-deprecated)
