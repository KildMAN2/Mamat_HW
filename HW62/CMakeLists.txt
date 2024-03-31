cmake_minimum_required(VERSION 3.25)
project(HW62)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW62
        generic-field.h
        generic-string.h
        input.h
        string-array.cpp
        string-array.h
        string.cpp
        string.h port.h port.cpp ip.h ip.cpp)
