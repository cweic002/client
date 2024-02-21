cmake_minimum_required(VERSION 3.5)

project(fSocketClientLinux VERSION 0.1 LANGUAGES CXX)

add_library(fSocketClientLinux
    "fSocketClientLinux.h"
    "fSocketClientLinux.cpp"
)

target_link_libraries(fSocketClientLinux PUBLIC socketClientLinux)
target_include_directories(fSocketClientLinux PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})
