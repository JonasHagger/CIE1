#include <iostream>
#include <cmath>

using namespace std;

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%
//      Classes
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%
namespace Cie {

    class DoubleVector {
    public:
        DoubleVector(int initArraySize);
        ~DoubleVector();

        void PrintVector();
        int getSize();
        double& At(int i);
        void SetAt(int i, double d);
        void Resize(int newArraySize);
        void PushBack();
        double calcEuclideanNorm();
    private:
        int arraySize;
        void CreateVector();
        double* array;
    };

    // ===========================
    //      Constructor
    // ===========================

    DoubleVector::DoubleVector(int initArraySize)
    : arraySize(initArraySize), array(new double[initArraySize])
    {
        if (initArraySize <= 0) {
            throw std::invalid_argument("Array size must be > 0");
        }

        CreateVector();
    }

    // old and unsafe version
    /*
    DoubleVector::DoubleVector(int initArraySize) {
        if (initArraySize <= 0) {cout << "This no work :(";}
        else {
            arraySize = initArraySize;
            array = new double[arraySize];
            CreateVector();
        }
    }
    */

    // ===========================
    //      Destructor
    // ===========================

    DoubleVector::~DoubleVector() {
        delete[] array;
    }


    // ===========================
    //      Methods
    // ===========================
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

    int DoubleVector::getSize() {
        return arraySize;
    }

    double& DoubleVector::At(int i) {
        return array[i];
    }

    void DoubleVector::SetAt(int i, double d) {
        At(i) = d;
    }

    void DoubleVector::Resize(int newArraySize) {
        double* old_array = array;                      // store old values
        double* new_array = new double[newArraySize];   // new array

        for (int i=0; i < arraySize; ++i) {
            new_array[i] = old_array[i];
        }
        if (arraySize < newArraySize) {
            for (int i = arraySize; i < newArraySize; ++i) {
                new_array[i] = 0;
            }
        }
        arraySize = newArraySize;           // overwrite size to new size
        array = new_array;
        delete [] old_array;
        PrintVector();
    }

    void DoubleVector::PushBack() {
        cout << "Arraysize was "<< arraySize << endl;
        int newArraySize = arraySize + 1;
        cout << "Arraysize becomes "<< newArraySize << endl;
        Resize(newArraySize);
        arraySize = newArraySize;
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

// %%%%%%%%%%%%%%%%%%%%%%%%%%%%
//      Functions
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%


void calcDotProduct(Cie::DoubleVector Array1, Cie::DoubleVector Array2) {
    double sum = 0;
    for (int i = 0; i < Array1.getSize(); i++) {
        sum += Array1.At(i) * Array2.At(i);
    }
    cout << "Dot Product = " << sum << endl;
}


// %%%%%%%%%%%%%%%%%%%%%%%%%%%%
//      Main
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%

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
    cout << "Value At 0 = " << Array.At(0) << endl;
    Array.SetAt(0, 42);
    cout << "New Value At 0 = " << Array.At(0) << endl;

    cout << "Resize to 5" << endl;
    Array.Resize(5);

    cout << "Pushback" << endl;
    Array.PushBack();

    // create another instance
    Cie::DoubleVector Arrayyy(arraySize);
    Cie::DoubleVector Hurrayyy(arraySize);
    // Dot Product
    calcDotProduct(Arrayyy, Hurrayyy);

    return 0;
}
