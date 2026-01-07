#include "05_DoubleVector.hpp"
#include <iostream>

namespace cie {
    // Static fields come first
    int DoubleVector::vectorCount = 0;


    // Constructor
    DoubleVector::DoubleVector(int initSize)
        :vectorSize(initSize)
    {
        if (vectorSize > 0) {
            array = new double[vectorSize];
            vectorCount++;
            for (int i = 0; i < vectorSize; i++) {
                array[i] = 0;
            }
        }
    }
    // overloading
    DoubleVector::DoubleVector()
        : DoubleVector(0)
    {}

    // Copy Constructor
    DoubleVector::DoubleVector(const DoubleVector& other)
        :vectorSize(other.vectorSize), array(new double[vectorSize])
    {
        for (int i = 0; i < vectorSize; i++) {
            array[i] = other.array[i];
        }
        vectorCount++;
    }

    // Assignment Constructor
    DoubleVector& DoubleVector::operator=(const DoubleVector& other) {
        if (this == &other) { return *this; }
        delete[] array;
        vectorSize = other.vectorSize;
        array = new double[vectorSize];
        for (int i = 0; i < vectorSize; i++) {
            array[i] = other.array[i];
        }
        return *this;
    }

    // Destructor
    DoubleVector::~DoubleVector() {
        delete[] array;
        std::cout << "Destroyed DoubleVector" << std::endl;
    }

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    // Instance Methods
    // at() as REFERENCE
    double& DoubleVector::at(int index) {
        return array[index];
    }

    // size
    int DoubleVector::size() {
        return vectorSize;
    }

    // setAt()
    void DoubleVector::setAt(int index, double value) {
        at(index) = value;
    }

    // resize()
    void DoubleVector::resize(int newSize) {
        double* newArray = new double[newSize];

        int maxSize = (vectorSize > newSize) ? vectorSize : newSize;
        int minSize = (vectorSize < newSize) ? vectorSize : newSize;

        for ( int i = 0; i < minSize; i++) {
            newArray[i] = array[i];
        }

        if (vectorSize < newSize) {
            for (int i = vectorSize; i < newSize; i++) {
                newArray[i] = 0;
            }
        }

        delete [] array;
        array = newArray;
        vectorSize = newSize;
    }

    // pushback
    void DoubleVector::push_back(double value) {
        int newSize = vectorSize + 1;
        resize(newSize);
        // vectorSize = newSize;
        // not needed bcs in resize() its redeclared
        array[(vectorSize-1)] = value;
    }

    // print()
    void DoubleVector::print() {
        std::cout << "Array: [ ";
        for (int i =0; i < size(); i++) {
            std::cout << at(i) << " ";
        }
        std::cout << "]" << std::endl;
    }


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    // printVector
    void DoubleVector::printVector(const DoubleVector& Vector) {
        std::cout << "Array: [";
        for (int i = 0; i < Vector.vectorSize; i++) {
            std::cout << " " << Vector.array[i] << " ";
        }
        std::cout << "]" << std::endl;
    }

    // printVectorCount
    void DoubleVector::printVectorCount() {
        std::cout << "Vectorcount = " << vectorCount << std::endl;
    }



} // namespace cie
