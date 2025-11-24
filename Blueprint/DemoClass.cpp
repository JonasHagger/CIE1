#include "DemoClass.h"

// ==================================
// static fields must be defined here
// ==================================
int DemoClass::instanceCounter = 0;
int DemoClass::totalCreatedObjects = 0;


// ==================================
// ----------Constructors----------
// ==================================
DemoClass::DemoClass(int initialValue, int readOnly)
    : value(initialValue), readonlyValue(readOnly)
{
    CountInstance();
}

// old and unsafe
/*
DemoClass::DemoClass(int initialValue, int readOnly) {
    value = initialValue;
    readonlyValue = readOnly;

    CountInstance();
}
*/

DemoClass::DemoClass()
    : DemoClass(0, 0)
{}


// ==================================
// ----------Getters / Setters----------
// ==================================
void DemoClass::setValue(int v) {
    if (v >= 0) value = v;
}


// ==================================
// ----------Methods----------
// ==================================
void DemoClass::Increase(int amount) {
    value += amount;
    readonlyValue += amount;
}

void DemoClass::PrintInfo() const {
    std::cout << "Name: " << name << "\n";
    std::cout << "Value: " << value << "\n";
    std::cout << "ReadonlyValue: " << readonlyValue << "\n";
}


// ==================================
// ----------Static Methods----------
// ==================================
void DemoClass::CountInstance() {
    instanceCounter++;
    totalCreatedObjects++;
}

void DemoClass::PrintStatistics() {
    std::cout << "Objects created: " << totalCreatedObjects << "\n";
    std::cout << "InstanceCounter: " << instanceCounter << "\n";
}
