cmake_minimum_required(VERSION 3.25 FATAL_ERROR)
project(ElferEngine VERSION 0.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

include(global_settings)

# ---- Main project's files ----
add_subdirectory(source)
add_subdirectory(dependencies)