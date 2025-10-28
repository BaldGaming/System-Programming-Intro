cmake_minimum_required(VERSION 3.30)
project(q_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(q_3
        main.c
        functions.c
        header.h
)