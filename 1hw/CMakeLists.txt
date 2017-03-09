cmake_minimum_required(VERSION 3.1)
project(ast)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        ast.hpp
        eval.hpp
        main.cpp
        print.hpp
        type.hpp
        value.hpp)

add_executable(ast ${SOURCE_FILES})

