cmake_minimum_required(VERSION 3.17)
project(CPTS_223)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(CPTS_223
        AVLtree.cpp
        AVLtree.h
        main.cpp)
