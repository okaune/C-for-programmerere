cmake_minimum_required(VERSION 2.8)

project(ov2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra")

add_executable(ov2 main.cpp)
