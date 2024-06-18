cmake_minimum_required(VERSION 3.15)

add_executable(TestProject
catch_amalgamated.hpp catch_amalgamated.cpp
main.cpp)

target_include_directories(TestProject PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(TestProject PRIVATE NCore)