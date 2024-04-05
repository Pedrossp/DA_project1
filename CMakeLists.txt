cmake_minimum_required(VERSION 3.27)
project(DA_project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(Project1DataSetSmall)

add_executable(DA_project1
        src/City.h
        src/DataManip.h
        src/Reservoir.h
        src/Station.h
        src/City.cpp
        src/DataManip.cpp
        src/Reservoir.cpp
        src/Station.cpp
        src/main.cpp
        src/Graph.cpp
        src/Graph.h
        src/Menu.h
        src/Menu.cpp
)