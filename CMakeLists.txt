cmake_minimum_required(VERSION 4.0)
project(Cymphony)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)

add_executable(Cymphony src/main.cpp
        src/token_utils.cpp
        src/lexer.cpp
        src/token.cpp)
