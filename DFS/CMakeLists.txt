cmake_minimum_required(VERSION 2.8)
project(DFS)
include_directories(${DFS_SOURCE_DIR})
add_executable(DFS_testing
	graph_test.cpp
	graph.h
	gtest/gtest-all.cc
	gtest/gtest.h
	gtest/gtest_main.cc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
target_link_libraries(DFS_testing -pthread)
