cmake_minimum_required(VERSION 3.26)
project(ScientificComputing)

set(CMAKE_CXX_STANDARD 17)

add_executable(ScientificComputing main.cpp
        Algorithms/DIrect/Round_Integer/round_integer.cpp
        Algorithms/DIrect/Round_Integer/round_integer.h
        Algorithms/Iterative/Square_Root/square_root.cpp
        Algorithms/Iterative/Square_Root/square_root.h
        Algorithms/Iterative/N-th_Root/n-th_root.cpp
        Algorithms/Iterative/N-th_Root/n-th_root.h)
