#include "05_DoubleVector.hpp"
#include <iostream>

using namespace std;


namespace cie {

// Static fields
int DoubleVector::vecCounter = 0;

// Constructor
DoubleVector::DoubleVector(int initSize)
    : vecSize(initSize) {
    vecCounter++;
    array = new double[vecSize];
    // arrayList = new DoubleVector[vecCounter];

    for (int i = 0; i < vecSize; i++) {
        array[i] = 0;
    }
}

// Overloading Constructor
DoubleVector::DoubleVector() : DoubleVector(0) {}

// Destructor
DoubleVector::~DoubleVector() {
    delete[] array;
}

// Memberfunctions
double& DoubleVector::at(int index) {
    return array[index];
}

int DoubleVector::size() {
    return vecSize;
}

//setAt()
void DoubleVector::setAt(int index, double value) {
    at(index) = value;
}

//resize()
void DoubleVector::resize(int newSize) {
    double* newArray = new double[newSize];

    int minSize = (vecSize < newSize) ? vecSize : newSize;

    for (int i = 0; i < minSize; i++)
        newArray[i] = array[i];

    for (int i = minSize; i < newSize; i++)
        newArray[i] = 0;

    delete[] array;
    array = newArray;
    vecSize = newSize;
}

//pushback()
void DoubleVector::push_back(double value) {
    resize(vecSize + 1);
    array[vecSize - 1] = value;
}


// Static functions
void DoubleVector::print(DoubleVector& Vector) {
    cout << "Vector with Address " << &Vector << endl;
    for (int i = 0; i < Vector.size(); i++) {
        cout << Vector.at(i) << " ";
    }
    cout << endl;
}

void DoubleVector::printVecCount() {
    cout << "Vectorcount = " << vecCounter;
    cout << endl;
}

void DoubleVector::dotProduct(DoubleVector& V1, DoubleVector& V2) {
    double sum = 0;
    for (int i = 0; i < V1.size(); i++) {
        sum += V1.at(i) * V2.at(i);
    }
    cout << "Dot Product = " << sum << endl;
}


} //namespace cie
