cmake_minimum_required(VERSION 3.27)
project(vulkan LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include(cmake/linter.cmake)

add_subdirectory(hello)
add_subdirectory(triangle)
