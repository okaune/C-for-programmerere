cmake_minimum_required(VERSION 2.8)

project(ov4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter")

INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

add_executable(ov4_1 task1.cpp)
add_executable(ov4_2 task2.cpp)
target_link_libraries(ov4_2 ${GTKMM_LIBRARIES})
