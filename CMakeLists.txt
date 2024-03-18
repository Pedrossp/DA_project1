cmake_minimum_required(VERSION 3.27)
project(DA_project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project1DataSetSmall)

add_executable(DA_project1
        Graph.cpp
        Graph.h)
