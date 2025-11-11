#include <iostream>
#include "02_vectorfunctions.hpp"

using namespace std;
using namespace vectorfunctions;

int main() {
    // init param
    const int arraySize = 3;

    // init arrays
    double array1[arraySize];
    double array2[arraySize];


    cout << "Drecks CIE 1 ich hab so kb mehr Hunde" << endl;
    // assign arrays
    cout << "Enter values for vector 1:" << endl;
    assignArrayValues(arraySize, array1);
    printArray(arraySize, array1);

    cout << "\nEnter values for vector 2:" << endl;
    assignArrayValues(arraySize, array2);
    printArray(arraySize, array2);

    cout << endl;

    // functions
    calcDotProduct(arraySize, array1, array2);
    calcEuclideanNorm(arraySize, array1);
    maxNorm(arraySize, array1);

    return 0;
}