//
// Created by matxin on 9/11/23.
//
#include <stdexcept>


#ifndef SCIENTIFICCOMPUTING_INDEXOUTOFBOUNDSEXCEPTION_H
#define SCIENTIFICCOMPUTING_INDEXOUTOFBOUNDSEXCEPTION_H


class IndexOutOfBoundsException : public std::out_of_range {
public:
    explicit IndexOutOfBoundsException(const std::string& message)
        : std::out_of_range(message) {}
};


#endif //SCIENTIFICCOMPUTING_INDEXOUTOFBOUNDSEXCEPTION_H
