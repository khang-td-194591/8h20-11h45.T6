cmake_minimum_required(VERSION 3.17)
project(untitled C)

set(CMAKE_C_STANDARD 99)

include_directories(libfdr)

add_executable(untitled main.c libfdr/dllist.c libfdr/jrb.c libfdr/jval.c)