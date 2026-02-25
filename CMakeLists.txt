cmake_minimum_required(VERSION 4.1)
project(BinaryTree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(BinaryTree
        main.cpp
        src/CSVparser.cpp
        src/Bid.cpp
        src/Menu.cpp
        src/BinarySearchTree.cpp
)

target_include_directories(BinaryTree PRIVATE
        ../HashTable/include
)

target_compile_definitions(BinaryTree PRIVATE
        DATA_DIR="${CMAKE_SOURCE_DIR}/data"
)
