cmake_minimum_required(VERSION 3.26)
project(cpp_chess_engine)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(cpp_chess_engine
        main.cpp
        lookup.cpp
        bitboard.cpp
        init.cpp
)
