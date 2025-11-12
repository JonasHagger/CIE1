#include <iostream>
#include "02_vectorfunctions.hpp"

using namespace std;
using namespace vectorfunctions;

int main() {
    cout << "CIE 1 :)" << endl;

    // init arraySize
    int arraySize;
    cout << "Enter vectorsize:" << endl;
    cin >> arraySize;


    // init arrays
    double* array1 = new double[arraySize];
    double* array2 = new double[arraySize];
    //double array2[arraySize];


    // assign arrays
    cout << "Enter values for vector 1:" << endl;
    assignArrayValues(arraySize, array1);
    printArray(arraySize, array1);

    cout << "\nEnter values for vector 2:" << endl;
    assignArrayValues(arraySize, array2);
    printArray(arraySize, array2);

    cout << endl;

    // functions
   
    
    int userChoice;
    cout << "What to do?" << endl;
    cout << "1 - DotProduct" << endl;
    cout << "2 - Ecilidean norm" << endl;
    cout << "3 - max norm" << endl;
    cout << "4 - TERMINATEs the PROG" << endl;

    cin >> userChoice;;
    
    switch (userChoice) {
        case 1:
            calcDotProduct(arraySize, array1, array2);
            break;
        case 2:
            calcEuclideanNorm(arraySize, array1);
            break;
        case 3:
            maxNorm(arraySize, array1);
            break;
        default:
            break;
    }


    // example from lecture
    double* arr = new double[100];
    
    // BAD only deletes pointer, not data
    // delete arr 

    // only deletes pointer, not data
    delete[] arr;


    return 0;
}