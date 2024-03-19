cmake_minimum_required(VERSION 3.27)
project(DA_project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project1DataSetSmall)

add_executable(DA_project1
        City.h
        DataManip.h
        Graph.h
        Reservoir.h
        Station.h
        City.cpp
        DataManip.cpp
        Reservoir.cpp
        Station.cpp
        main.cpp
)
