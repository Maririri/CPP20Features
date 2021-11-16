cmake_minimum_required(VERSION 3.20)
project(CPP20Features)

set(CMAKE_CXX_STANDARD 20)

add_executable(concepts concepts.cpp)
add_executable(coroutines coroutines.cpp)
