cmake_minimum_required(VERSION 4.1)
project(CourseList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
        csvparser
        GIT_REPOSITORY https://github.com/vincentlaucsb/csv-parser.git
        GIT_TAG master
)

FetchContent_MakeAvailable(csvparser)

add_executable(CourseList
        main.cpp
        src/View.cpp
        src/BinarySearchTree.cpp
        include/Constants.hpp
        src/DataService.cpp
)

target_link_libraries(CourseList PRIVATE csv)

target_include_directories(CourseList PRIVATE
        ../CourseList/include
)

target_compile_definitions(CourseList PRIVATE
        DATA_DIR="${CMAKE_SOURCE_DIR}/data"
)
