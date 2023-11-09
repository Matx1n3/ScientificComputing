//
// Created by matxin on 8/11/23.
//

#include "jacobi.h"
#include <stdio.h>
#include "/home/matxin/WorkSpace/Uni/3ero/CC/ScientificComputing/Utils/utils.h"
#include "../../../Models/Matrix.h"

/**
 *
 * @param expanded_matrix: Expanded matrix representing the system of linear equations
 * @param sol: Matrix with dimensions (rows in expansion_matrix) x 1. The solution will be stored here
 * @param tolerance: The amount that the solution has to improve between two iterations in order to consider it
 *                   good enough and stop the execution.
 *
 * pre: The coefficient Matrix is strictly dominant diagonal, otherwise, the algorithm may not converge and will
 *      stay in a loop until manually stopped.
 */

double* aproximate_solution_jacobi(Matrix* expanded_matrix, Matrix* sol, double tolerance){

    Matrix t = Matrix(expanded_matrix->getRows(), expanded_matrix->getColumns()-1);

    for (int i = 0; i < t.getRows(); i++){
        for (int j = 0; j < t.getColumns(); j++){
            if (i != j){
                t.set((- expanded_matrix->get(i, j) / expanded_matrix->get(i, i)), i, j);
            }
            else{
                t.set(0.0, i, j);
            }
        }
    }
    
    Matrix c = Matrix(expanded_matrix->getRows(), 1);

    for (int i = 0; i < c.getRows(); i++) {
        c.set(expanded_matrix->get(i, expanded_matrix->getColumns()-1) / expanded_matrix->get(i, i), i, 0);
    }
    
    Matrix x = Matrix(expanded_matrix->getRows(), 1);
    Matrix x_new = Matrix(expanded_matrix->getRows(), 1);

    //  Para probar, mejorar aproximacion inicial luego
    for (int i = 0; i < expanded_matrix->getRows(); i++){
        x.set(1, i, 0);
    }

    double aux;
    int finished = 0;
    while (finished == 0){
        for (int i = 0; i < t.getRows(); i++){
            aux = 0;
            for (int j = 0; j < t.getRows(); j++){
                aux += t.get(i, j) * x.get(j, 0);
            }
            x_new.set(aux + c.get(i, 0), i, 0);
        }
        for (int i = 0; i < x.getRows(); i++) {
            finished = 1;
            if (abs(x_new.get(i, 0) - x.get(i, 0)) > tolerance){
                finished = 0;
            }
        }
        for (int i = 0; i < x.getRows(); i++){
            x.set(x_new.get(i, 0), i, 0);
        }
    }

    for (int i = 0; i < x_new.getRows(); i++) {
        sol->set(x_new.get(i, 0), i, 0);
    }
}


/**
 *
 * @param expanded_matrix: Expanded matrix representing the system of linear equations
 * @param sol: Matrix with dimensions (rows in expansion_matrix) x 1. The solution will be stored here
 * @param tolerance: The amount that the solution has to improve between two iterations in order to consider it
 *                   good enough and stop the execution.
 * @param max_iterations: Limit for the amount of iterations that the algorithm can go through.
 *
 * pre: The coefficient Matrix is strictly dominant diagonal, otherwise, the algorithm may not converge and will
 *      stay in a loop until manually stopped.
 */

double* aproximate_solution_jacobi(Matrix* expanded_matrix, Matrix* sol, double tolerance, int max_iterations){

    Matrix t = Matrix(expanded_matrix->getRows(), expanded_matrix->getColumns()-1);

    for (int i = 0; i < t.getRows(); i++){
        for (int j = 0; j < t.getColumns(); j++){
            if (i != j){
                t.set((- expanded_matrix->get(i, j) / expanded_matrix->get(i, i)), i, j);
            }
            else{
                t.set(0.0, i, j);
            }
        }
    }

    Matrix c = Matrix(expanded_matrix->getRows(), 1);

    for (int i = 0; i < c.getRows(); i++) {
        c.set(expanded_matrix->get(i, expanded_matrix->getColumns()-1) / expanded_matrix->get(i, i), i, 0);
    }

    Matrix x = Matrix(expanded_matrix->getRows(), 1);
    Matrix x_new = Matrix(expanded_matrix->getRows(), 1);

    //  Para probar, mejorar aproximacion inicial luego
    for (int i = 0; i < expanded_matrix->getRows(); i++){
        x.set(1, i, 0);
    }

    double aux;
    int finished = 0;
    int iterations = 0;
    while (finished == 0 & iterations < max_iterations){
        for (int i = 0; i < t.getRows(); i++){
            aux = 0;
            for (int j = 0; j < t.getRows(); j++){
                aux += t.get(i, j) * x.get(j, 0);
            }
            x_new.set(aux + c.get(i, 0), i, 0);
        }
        for (int i = 0; i < x.getRows(); i++) {
            finished = 1;
            if (abs(x_new.get(i, 0) - x.get(i, 0)) > tolerance){
                finished = 0;
            }
        }
        for (int i = 0; i < x.getRows(); i++){
            x.set(x_new.get(i, 0), i, 0);
        }
        iterations++;
    }

    for (int i = 0; i < x_new.getRows(); i++) {
        sol->set(x_new.get(i, 0), i, 0);
    }
}