cmake_minimum_required(VERSION 2.8.3)
project(leetcode)
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -march=native -O3 -pthread")

add_executable(main main.cpp)
