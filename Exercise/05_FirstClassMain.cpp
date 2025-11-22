#include <iostream>
#include <cmath>

using namespace std;

namespace Cie {

    class DoubleVector {
    public:
        int arraySize;
        DoubleVector(int initArraySize);

        void PrintVector();
        double calcEuclideanNorm();
    private:
        void CreateVector();
        double* array = new double[arraySize];
    };

    // Constructor
    DoubleVector::DoubleVector(int initArraySize) {
        arraySize = initArraySize;
        CreateVector();
    }

    // Methods
    void DoubleVector::CreateVector() {
        for (int i=0; i < arraySize; ++i) {
            cout << "Enter Arrayelement " << i << ": ";
            cin >>array[i];
        }
        cout << "Your Array is" << endl;
        PrintVector();
    }

    void DoubleVector::PrintVector() {
        for (int i=0; i < arraySize; ++i) {
            cout << array[i] << endl;
        }
    }

    double DoubleVector::calcEuclideanNorm() {
        double powSum = 0;
        for (int i = 0; i < arraySize; i++) {
            powSum += pow(array[i], 2);
        }
        double norm = sqrt(powSum);
        return norm;
    }


} // namespace cie

int main() {

    cout << "CIE 1 :)" << endl;

    // init arraySize from Userinput
    int arraySize;
    cout << "Enter vectorsize:" << endl;
    cin >> arraySize;

    // create instance
    Cie::DoubleVector Array(arraySize);

    // call Methods
    cout << "Euclidean Norm = " << Array.calcEuclideanNorm() << endl;

    return 0;
}
