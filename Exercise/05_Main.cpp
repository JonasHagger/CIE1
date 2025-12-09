#include <iostream>
#include "05_DoubleVector.hpp"
using namespace std;
using namespace cie;

int main()
{
    cout << "Hello World!" << endl;
    DoubleVector V1 (3);
    DoubleVector V2 (3);

    cout << "printing v1[0]: " << V1.at(0) << endl;
    cout << "printing v1.size(): " << V1.size() << endl;

    V1.setAt(0, 10);
    V1.setAt(1, 9);
    V1.setAt(2, 8);
    cout << "Setting v1 = [10, 9, 8]" << endl;
    DoubleVector::printVector(V1);

    cout << "Setting v1.size = 10" << endl;
    V1.resize(10);
    DoubleVector::printVector(V1);

    cout << "Setting v1.size = 2" << endl;
    V1.resize(2);
    DoubleVector::printVector(V1);

    cout << "Pushback with 5" << endl;
    V1.push_back(5);
    DoubleVector::printVector(V1);
    cout << "Pushback with 12913" << endl;
    V1.push_back(12913);
    DoubleVector::printVector(V1);
    DoubleVector::printVectorCount();

    cout << "Jetzt kommt v2" << endl;
    V2.print();

    return 0;
}