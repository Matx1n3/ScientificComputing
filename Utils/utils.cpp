//
// Created by matxin on 8/11/23.
//

#include "utils.h"
#include <cstdio>


void print_matrix(double* expanded_matrix, int rows, int columns){
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%f  ", expanded_matrix[i*columns+j]);
        }
        printf("\n");
    }
}

double abs(double val){
    if (val > 0.0){
        return val;
    }
    else {
        return -val;
    }
}