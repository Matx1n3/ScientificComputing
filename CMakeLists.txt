cmake_minimum_required(VERSION 3.26)
project(ScientificComputing)

set(CMAKE_CXX_STANDARD 17)

add_executable(ScientificComputing main.cpp
        Algorithms/Direct/Round_Integer/round_integer.cpp
        Algorithms/Direct/Round_Integer/round_integer.h
        Algorithms/Iterative/Square_Root/square_root.cpp
        Algorithms/Iterative/Square_Root/square_root.h
        Algorithms/Iterative/N-th_Root/n-th_root.cpp
        Algorithms/Iterative/N-th_Root/n-th_root.h
        Algorithms/Iterative/Sine/sine.cpp
        Algorithms/Iterative/Sine/sine.h
        Algorithms/Iterative/Sine/sine.cpp
        Algorithms/Iterative/Sine/sine.cpp
        Algorithms/Iterative/Jacobi/jacobi.cpp
        Algorithms/Iterative/Jacobi/jacobi.h
        Algorithms/Iterative/Jacobi/jacobi.h
        Algorithms/Iterative/Jacobi/jacobi.cpp
        Algorithms/Iterative/Sine/sine.cpp
        Utils/utils.cpp
        Utils/utils.h
        Models/Matrix.cpp
        Models/Matrix.h
        Exceptions/IndexOutOfBoundsException.h
        Algorithms/Direct/Power/power.cpp
        Algorithms/Direct/Power/power.h
        Exceptions/MatrixDimensionException.h
)
