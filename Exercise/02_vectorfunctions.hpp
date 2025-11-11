#ifndef VECTORFUNCTIONS
#define VECTORFUNCTIONS

#include <iostream>
#include <cmath>

namespace vectorfunctions {

    void assignArrayValues(int arraySize, double array[]);
    void printArray(int arraySize, double array[]);
    void calcDotProduct(int arraySize, double array1[], double array2[]);
    void calcEuclideanNorm(int arraySize, double array[]);
    void maxNorm(int arraySize, double array[]);

}

#endif
