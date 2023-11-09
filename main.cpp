#include <iostream>
#include "Algorithms/Iterative/N-th_Root/n-th_root.h"
#include "Algorithms/Iterative/Square_Root/square_root.h"
#include "Models/Matrix.h"
#include "Algorithms/Iterative/Jacobi/jacobi.h"
#include "Utils/utils.h"

int main() {
    double vals[6] = {3.0, 1.0, 5.0, 1.0, 2.0,5.0};
    Matrix mat = Matrix(vals, 2, 3);
    Matrix sol = Matrix(2, 1);
    aproximate_solution_jacobi(&mat, &sol, 0.00001, 99);
    sol.print();
}