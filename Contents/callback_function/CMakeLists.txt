cmake_minimum_required(VERSION 3.16)
project(callback_function)

set(CMAKE_CXX_STANDARD 14)

add_executable(callback_function  callback_demo.cpp even.cpp even.h)