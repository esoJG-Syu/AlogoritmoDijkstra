cmake_minimum_required(VERSION 3.28)
project(proyecto3 C)

set(CMAKE_C_STANDARD 90)

add_executable(proyecto3 main.c
        dijkstra.h
        utils.h)
