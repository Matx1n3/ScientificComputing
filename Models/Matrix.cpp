//
// Created by matxin on 9/11/23.
//

#include <cstdio>
#include "Matrix.h"
#include "/home/matxin/WorkSpace/Uni/3ero/CC/ScientificComputing/Exceptions/IndexOutOfBoundsException.h"
#include "/home/matxin/WorkSpace/Uni/3ero/CC/ScientificComputing/Exceptions/MatrixDimensionException.h"


Matrix::Matrix(double* values, int rows, int columns) {
    this->values = values;
    this->rows = rows;
    this->columns = columns;
}

Matrix::Matrix(int rows, int columns) {
    this->values = (double *) malloc(rows*columns*sizeof(double));
    for (int i = 0; i < rows * columns; i++){
        values[i] = 0;
    }
    this->rows = rows;
    this->columns = columns;
}

void Matrix::print() {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            printf("%f  ", values[i*columns+j]);
        }
        printf("\n");
    }
}

int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

double Matrix::get(int i, int j) const {
    if (i >= rows || j >= columns) {
        throw IndexOutOfBoundsException("Trying to access index (" + std::to_string(i) + ", " + std::to_string(j) + "), but matrix is " +  std::to_string(rows) + " * " + std::to_string(columns));
    }
    if ( i < 0 || j < 0) {
        throw IndexOutOfBoundsException("Indexes must be non-negative");
    }
    else {
        return values[i*columns+j];
    }
}

void Matrix::set(double val, int i, int j) {
    if (i >= rows || j >= columns) {
        throw IndexOutOfBoundsException("Trying to access index (" + std::to_string(i) + ", " + std::to_string(j) + "), but matrix is " +  std::to_string(rows) + " * " + std::to_string(columns));
    }
    if ( i < 0 || j < 0) {
        throw IndexOutOfBoundsException("Indexes must be non-negative");
    }
    else {
        values[i*columns+j] = val;
    }
}

Matrix Matrix::operator+(const Matrix &other) const {
    if (rows != other.getRows() || columns != other.getColumns()){
        throw MatrixDimensionException("addition", rows, columns, other.rows, other.columns);
    }

    Matrix result(rows, columns);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.set(get(i, j) + other.get(i, j), i, j);
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
    if (rows != other.getRows() || columns != other.getColumns()){
        throw MatrixDimensionException("subtraction", rows, columns, other.rows, other.columns);
    }

    Matrix result(rows, columns);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.set(get(i, j) - other.get(i, j), i, j);
        }
    }

    return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
    if (columns != other.getRows()) {
        throw MatrixDimensionException("multiplication", rows, columns, other.getRows(), other.getColumns());
    }

    Matrix result(rows, other.getColumns());

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.getColumns(); ++j) {
            for (int k = 0; k < columns; ++k) {
                result.set(get(i, k) * other.get(k, j), i, j);
            }
        }
    }

    return result;
}

Matrix Matrix::operator*(const double &other) const {

    Matrix result(rows, columns);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            result.set(get(i, j) * other, i, j);
        }
    }

    return result;
}


