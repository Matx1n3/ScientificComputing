//
// Created by matxin on 8/11/23.
//

#ifndef SCIENTIFICCOMPUTING_JACOBI_H
#define SCIENTIFICCOMPUTING_JACOBI_H


#include "../../../Models/Matrix.h"

class jacobi {

};
double* aproximate_solution_jacobi(Matrix* expanded_matrix, Matrix* sol, double tolerance);
double* aproximate_solution_jacobi(Matrix* expanded_matrix, Matrix* sol, double tolerance, int max_iterations);
#endif //SCIENTIFICCOMPUTING_JACOBI_H
