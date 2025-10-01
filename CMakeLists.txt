cmake_minimum_required(VERSION 3.10)

project(auto_sorting-machine.git CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/includes)

add_executable(auto_sorting-machine.git main.cpp
        train/preprocessing.cpp
        tools/tools.cpp
        includes/tools/tools.h
        includes/trainer.h)
