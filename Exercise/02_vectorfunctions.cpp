#include "02_vectorfunctions.hpp"
#include <iostream>
#include <cmath>

using namespace std;

namespace vectorfunctions {

    void assignArrayValues(int arraySize, double array[]) {
        for (int i = 0; i < arraySize; i++) {
            cout << "Enter value for vector position " << i << ": ";
            cin >> array[i];
        }
    }

    void printArray(int arraySize, double array[]) {
        cout << "Vector = ";
        for (int i = 0; i < arraySize; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void calcDotProduct(int arraySize, double array1[], double array2[]) {
        double sum = 0;
        for (int i = 0; i < arraySize; i++) {
            sum += array1[i] * array2[i];
        }
        cout << "Dot Product = " << sum << endl;
    }

    void calcEuclideanNorm(int arraySize, double array[]) {
        double powSum = 0;
        for (int i = 0; i < arraySize; i++) {
            powSum += pow(array[i], 2);
        }
        double norm = sqrt(powSum);
        cout << "Euclidean Norm = " << norm << endl;
    }

    void maxNorm(int arraySize, double array[]) {
        double maxVal = fabs(array[0]);
        for (int i = 1; i < arraySize; i++) {
            if (fabs(array[i]) > maxVal) {
                maxVal = fabs(array[i]);
            }
        }

        cout << "Max Norm1 = " << maxVal << endl;

        // alt
        double maxValPnt = *max_element(array, array + arraySize);
        cout << "Max Norm2 = " << maxValPnt << endl;
    }

} // namespace vectorfunctions
