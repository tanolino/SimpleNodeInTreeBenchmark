cmake_minimum_required(VERSION 3.15)

project(NCore
VERSION 1.0
DESCRIPTION "Core for a game engine"
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory("3rd_glm")
add_subdirectory(NCore)
add_subdirectory(TestProject)