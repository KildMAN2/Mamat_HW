cmake_minimum_required(VERSION 3.25)
project(HW_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(HW_6
        generic-field.h
        generic-string.h
        input.h
        ip.cpp
        ip.h
        main.cpp
        port.cpp
        port.h
        string-array.cpp
        string-array.h
        string.cpp
        string.h)
