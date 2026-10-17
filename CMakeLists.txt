cmake_minimum_required(VERSION 3.16)
project(vhlibtimerstamp VERSION 0.0.2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/version.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/generated/version_timerstamp.h"
)

add_library(vhlib_timerstamp STATIC)

target_sources(vhlib_timerstamp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vhtimerstamp.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vhtimerstamp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/vhtimeaverager.hpp
)

target_include_directories(vhlib_timerstamp PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    "${CMAKE_CURRENT_BINARY_DIR}/generated"
)
