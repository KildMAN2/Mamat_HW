cmake_minimum_required(VERSION 3.25)
project(HW6 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(HW6
        generic-field.h
        generic-string.h
        input.h)
