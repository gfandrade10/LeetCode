cmake_minimum_required(VERSION 3.0.0)
project(LeetCodeExecutable)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_SHARED_LIBRARY_PREFIX "lib")
set(CMAKE_CXX_FLAGS "-g -O2 -Wall -Werror -Wpedantic")

#compiling
set(MAIN ${SOURCE})
add_executable(${PROJECT_NAME} ${MAIN})

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "LeetApp")

add_custom_target(run
    COMMAND ${CMAKE_COMMAND} -E echo "Compiling with CMake!"
    COMMAND ${CMAKE_COMMAND} -E echo "")
