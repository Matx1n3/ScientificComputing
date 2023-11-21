#include <iostream>
#include "Algorithms/Iterative/N-th_Root/n-th_root.h"
#include "Algorithms/Iterative/Square_Root/square_root.h"
#include "Models/Matrix.h"
#include "Algorithms/Iterative/Jacobi/jacobi.h"
#include "Utils/utils.h"
#include "Algorithms/Direct/Power/power.h"

int main() {
    double vals[6] = {2.0, 1.0, 3.0, 3.0, 2.0,6.0};
    Matrix mat = Matrix(vals, 2, 3);
    Matrix sol = Matrix(2, 1);
    aproximate_solution_jacobi(&mat, &sol, 20);
    sol.print();

    Matrix sol2 = Matrix(2, 1);
    aproximate_solution_jacobi(&mat, &sol2, 20, 9);
    sol2.print();

    Matrix mul = Matrix(2, 1);
}