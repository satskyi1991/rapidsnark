cmake_minimum_required(VERSION 3.5)

project(test_fr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test_fr fr.o main.cpp fr.cpp)

 target_link_libraries( test_fr gmp )
