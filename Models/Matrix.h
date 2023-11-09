//
// Created by matxin on 9/11/23.
//

#ifndef SCIENTIFICCOMPUTING_MATRIX_H
#define SCIENTIFICCOMPUTING_MATRIX_H


class Matrix {
public:
    Matrix(double* values, int rows, int columns);
    Matrix(int rows, int columns);
    void print();
    int getRows() const;
    int getColumns() const;
    double get(int i, int j);
    void set(double val, int i, int j);

private:
    double *values;
    int rows;
    int columns;
};


#endif //SCIENTIFICCOMPUTING_MATRIX_H
