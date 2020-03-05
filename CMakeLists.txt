cmake_minimum_required(VERSION 3.8)

project(wrestler)

set(Boost_INCLUDE_DIR /usr/local/src/boost)
include_directories(${Boost_INCLUDE_DIR})

add_subdirectory(lib)
add_subdirectory(tests)
