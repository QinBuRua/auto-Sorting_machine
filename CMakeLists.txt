cmake_minimum_required(VERSION 3.10)

project(auto-sorting_machine CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR})

add_executable(auto-sorting_machine main.cpp
        train/preprocessing.cpp)