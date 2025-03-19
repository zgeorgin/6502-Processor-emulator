cmake_minimum_required(VERSION 3.10)

project(Processor)

add_executable(Processor main.cpp)
include_directories(headers/)
add_subdirectory(tests)