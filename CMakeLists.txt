cmake_minimum_required(VERSION 3.21)
project(Improved_TextEditor)

set(CMAKE_CXX_STANDARD 14)

add_executable(Improved_TextEditor main.cpp editor.cpp editor.h common.h validate_file.cpp validate_file.h user_input.cpp user_input.h)
