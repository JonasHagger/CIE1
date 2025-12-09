#ifndef CIE_DOUBLEVECTOR_HPP
#define CIE_DOUBLEVECTOR_HPP

namespace cie {
    class DoubleVector {
    private:
        int vecSize;
        double* array;

        // static DoubleVector arrayList;
        static int vecCounter;

    public:
        // Constructor
        DoubleVector(int initSize);
        DoubleVector();
        // Destructor
        ~DoubleVector();

        // Memberfunctions
        double& at(int index);
        int size();
        void setAt(int index, double value);
        void resize(int newSize);\
        void push_back(double value);

        // Static Functions
        static void print( DoubleVector& Vector);
        static void printVecCount();
        static void dotProduct( DoubleVector& V1,  DoubleVector& V2);
    }; // class DoubleVector
} //namespace cie

#endif //CIE_DOUBLEVECTOR_HPP