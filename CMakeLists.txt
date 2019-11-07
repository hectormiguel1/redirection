cmake_minimum_required(VERSION 2.15)
project(Assigment_5 C)

set(CMAKE_C_STANDARD 99)

add_executable(validation validation.c validation.h errorPrinter.c)
add_executable(display display.c display.h errorPrinter.c errorPrinter.h)