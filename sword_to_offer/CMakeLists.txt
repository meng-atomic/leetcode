cmake_minimum_required(VERSION 3.5)
project(sword_to_offer)

set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_list test/test_list.cpp)
add_executable(test_binary_tree test/test_binary_tree.cpp)
add_executable(cqueue cqueue.cpp)
add_executable(binary_search binary_search.cpp)
add_executable(fibonacci fibonacci.cpp)
add_executable(back_tracing back_tracking.cpp)
add_executable(dynamic_planning dynamic_planning.cpp)
add_executable(power power.cpp)