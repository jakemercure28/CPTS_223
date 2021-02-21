cmake_minimum_required(VERSION 3.17)
project(CPTS_223)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(CMAKE_BUILD_TYPE Debug)

add_executable(CPTS_223
        main.cpp)
