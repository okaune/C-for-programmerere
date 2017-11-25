cmake_minimum_required(VERSION 2.8)

project(mengde)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter")

add_executable(mengde main.cpp mengde.cpp)
