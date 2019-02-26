cmake_minimum_required(VERSION 3.9)
project(Roulette)

set(CMAKE_CXX_STANDARD 11)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(Roulette main.cpp)