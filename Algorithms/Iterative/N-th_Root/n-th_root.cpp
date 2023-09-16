//
// Created by matxin on 16/09/23.
//

#include "n-th_root.h"
#include "math.h"   //Delete later

double n_root(double a, int n){

    /*
     * This is a generalization of Heron's algorithm for computing square root approximations
     * that allows to compute the n-th square root of a number.
     */

    double error = 0.000000000000001;   //This will determine the error in the outcome

    double x = a/(double) n;    //For improvement: Start with a better approximation

    double y = x;   //The y variable will store the value of variable x in the previous iteration

    x = (x * (n-1) + (a / pow(x, (n-1))))/ (double) n;  //We compute the first value for x

    while(abs(x-y) > error) {   //While the error is bigger than wanted:
        y = x;  //Store x's value in y, so that we can use it in the next iteration
        x = (x * (n-1) + (a / pow(x, (n-1))))/ (double) n;  //Compute the new value for x
    }

    //Once here, the error is smaller than wanted, so it's a good enough approximation
    return x;
}