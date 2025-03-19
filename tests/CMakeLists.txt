cmake_minimum_required(VERSION 3.10)
project(Tests)

find_package(Catch2 3 REQUIRED)

include_directories(../headers/)
add_executable(Tests condReg_tests.cpp) 
target_link_libraries(Tests PRIVATE Catch2::Catch2WithMain)

