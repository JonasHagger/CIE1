#include <iostream>
#include "05_DoubleVector.hpp"
using namespace std;
using namespace cie;

int main()
{
    cout << "Hello World!" << endl;
    DoubleVector V1 (3);
    DoubleVector V2 (3);
    DoubleVector V3;

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

    cout << "Doing a Copy" << endl;
    DoubleVector V4 = V1;
    V4.print();
    DoubleVector::printVectorCount();
    cout << "Changing V4" << endl;
    V4.resize(1);
    V4.print();
    V1.print();

    cout << "make new V5" << endl;
    DoubleVector V5(4);
    V5.print();
    cout << "V5 Becomes V1" << endl;
    V5 = V1;
    V5.print();
    V1.print();
    V1.resize(10);
    V1.print();
    V5.print();

    return 0;
}