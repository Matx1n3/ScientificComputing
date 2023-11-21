//
// Created by matxin on 8/11/23.
//
#include "../../../Models/Matrix.h"


#ifndef SCIENTIFICCOMPUTING_JACOBI_H
#define SCIENTIFICCOMPUTING_JACOBI_H



double* aproximate_solution_jacobi(Matrix* expanded_matrix, Matrix* sol, int precision);
double* aproximate_solution_jacobi(Matrix* expanded_matrix, Matrix* sol, int precision, int max_iterations);

#endif //SCIENTIFICCOMPUTING_JACOBI_H
