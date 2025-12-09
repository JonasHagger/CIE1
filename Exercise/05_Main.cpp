#include <iostream>

#include "05_DoubleVector.hpp"

using namespace std;
using namespace cie;

void doubleVectorDemo() {
    int size = 3;
    DoubleVector V1 = DoubleVector(size);
    //DoubleVector V2 = V1;
    DoubleVector V2 = DoubleVector(size);
    DoubleVector V3 = DoubleVector(size);
    DoubleVector::print(V1);
    DoubleVector::printVecCount();
    // DoubleVector::vecCounter =1;
    cout << "V1 at 0: " << V1.at(0) << endl;

    cout << "V1 at 2 to 5 " << endl;
    V1.setAt(2,5);
    DoubleVector::print(V1);

    cout << "V1 smaller Size" << endl;
    V1.resize( 2);
    DoubleVector::print(V1);

    cout << "V1 bigger Size" << endl;
    V1.resize(size + 10);
    DoubleVector::print(V1);

    cout << "V2" <<endl;
    DoubleVector::print(V2);

    cout << "V1 smaller Size again" << endl;
    V1.resize(size);
    DoubleVector::print(V1);

    V3.push_back(69);
    DoubleVector::print(V3);

    V1.setAt(2,5);
    V2.setAt(2,10);
    DoubleVector::dotProduct(V1, V2);
}


int main() {
    cout << "Hello to DoubleVector fun" << endl;

    doubleVectorDemo();

    return 0;
}