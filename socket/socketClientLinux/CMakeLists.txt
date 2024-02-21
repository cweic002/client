cmake_minimum_required(VERSION 3.5)

project(socketClientLinux VERSION 0.1 LANGUAGES CXX)

add_library(socketClientLinux
    "socketClientLinux.h"
    "socketClientLinux.cpp"
)

target_include_directories(socketClientLinux PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

