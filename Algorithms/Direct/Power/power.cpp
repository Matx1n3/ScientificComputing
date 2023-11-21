//
// Created by matxin on 15/11/23.
//

#include "power.h"
double power(double base, int exp){

    if (exp == 0){
        return 1.0;
    }

    if (exp == 1){
        return base;
    }

    if (exp < 0){
        return 1 / power(base, -exp);
    }

    if (exp % 2 == 0){
        double half = power(base, exp/2);
        return half * half;
    }
    else {
        double half = power(base, (exp-1)/2);
        return base * half * half;
    }
}