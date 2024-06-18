cmake_minimum_required(VERSION 3.15)

add_library(NCore
NCore.hpp NCore.cpp
"pch_glm.hpp"
"pch_stl.hpp")
target_include_directories(NCore PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(NCore PUBLIC glm::glm)
target_precompile_headers(NCore PUBLIC "pch_glm.hpp" "pch_stl.hpp")