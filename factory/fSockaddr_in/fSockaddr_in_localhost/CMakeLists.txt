cmake_minimum_required(VERSION 3.5)

project(fSockaddr_in_localhost VERSION 0.1 LANGUAGES CXX)

add_library(fSockaddr_in_localhost
    "fSockaddr_in_localhost.h"
    "fSockaddr_in_localhost.cpp"
)

target_include_directories(fSockaddr_in_localhost PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

