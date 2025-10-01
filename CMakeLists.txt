cmake_minimum_required(VERSION 3.10)

project(auto_sorting-machine CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/includes)

add_executable(auto_sorting-machine
        includes/tools/tools.h
        includes/frontend_auto_sm.h
        includes/trainer.h

        main.cpp
        train/preprocessing.cpp
        tools/tools.cpp
        submodules/Json/code/src.cpp
        includes/tools/json.h)

