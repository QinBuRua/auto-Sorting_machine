cmake_minimum_required(VERSION 4.0)

project(auto_sorting-machine CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${PROJECT_SOURCE_DIR}/includes)

include(FetchContent)
FetchContent_Declare(
        json_git
        GIT_REPOSITORY https://github.com/QinBuRua/Json.git
        GIT_TAG main
)
FetchContent_MakeAvailable(json_git)

add_executable(auto_sorting-machine
        main.cpp
        train/preprocessing.cpp
        tools/tools.cpp
)
target_link_libraries(auto_sorting-machine PRIVATE json_lib)


