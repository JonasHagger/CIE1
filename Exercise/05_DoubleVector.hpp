#pragma once
#ifndef CIE_DOUBLEVECTOR_H
#define CIE_DOUBLEVECTOR_H

namespace cie {
    class DoubleVector {
    private:
        // fields
        int vectorSize;
        double* array;

        static int vectorCount;

    public:
        // Constructors
        DoubleVector(int initSize);
        DoubleVector();
        DoubleVector(const DoubleVector& other);
        DoubleVector& operator=(const DoubleVector& other);

        // Destructors
        ~DoubleVector();

        // Instance Methods
        double& at(int index);
        int size();
        void setAt(int index, double value);
        void resize(int newSize);
        void push_back(double value);
        void print();

        //Static Method
        static void printVector(const DoubleVector& Vector);
        static void printVectorCount();
        static void dotProduct(DoubleVector V1, DoubleVector V2);
    };
}

#endif //CIE_DOUBLEVECTOR_H