//
// Created by matxin on 21/11/23.
//
#include <stdexcept>

#ifndef SCIENTIFICCOMPUTING_MATRIXDIMENSIONEXCEPTION_H
#define SCIENTIFICCOMPUTING_MATRIXDIMENSIONEXCEPTION_H



class MatrixDimensionException : public std::exception {
private:
    std::string message;

public:
    MatrixDimensionException(const std::string& operation, int rows1, int cols1, int rows2, int cols2) noexcept {
        message = "Couldn't perform operation " + operation + " with matrices of dimension (" + std::to_string(rows1) + "x" + std::to_string(cols1) +
                  ") and (" + std::to_string(rows2) + "x" + std::to_string(cols2) + ").";
    }

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //SCIENTIFICCOMPUTING_MATRIXDIMENSIONEXCEPTION_H
