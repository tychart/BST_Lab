cmake_minimum_required(VERSION 3.15)
project(bst_lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(scratch scratch.cpp BST.cpp BST.h)

add_executable(tests tests.cpp BST.cpp BST.h)

