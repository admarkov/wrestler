cmake_minimum_required(VERSION 3.15)
project(wrestler)

set(CMAKE_CXX_STANDARD 14)

add_library(wrestler wrestler.cpp wrestler.h config.h)