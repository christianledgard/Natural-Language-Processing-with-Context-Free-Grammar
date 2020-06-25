cmake_minimum_required(VERSION 3.10)
project(c__)

set(CMAKE_CXX_STANDARD 20)


add_executable(Parser main.cpp gramatica.cpp CYK.cpp gramatica.h CYK.h )
