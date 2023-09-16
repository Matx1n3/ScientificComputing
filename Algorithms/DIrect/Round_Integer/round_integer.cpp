//
// Created by matxin on 16/09/23.
//

#include "round_integer.h"

int round_integer(double a){
    if (a > 0.0f) {
        return (int) (a + 0.5);
    }
    else {
        return (int) (a - 0.5);
    }
}