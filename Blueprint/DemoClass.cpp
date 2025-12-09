#include "DemoClass.h"
#include <utility> // for std::move

namespace Demo {

    // ==================================
    // static fields must be defined here
    // ==================================
    int DemoClass::instanceCounter = 0;
    int DemoClass::totalCreatedObjects = 0;


    // ==================================
    // ----------Constructors----------
    // ==================================
    // Basic Constructor
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

    // Overloaded Constructor (delegating)
    DemoClass::DemoClass()
        : DemoClass(0, 0)
    {
    }

    // Copy Constructor
    DemoClass::DemoClass(const DemoClass& other)
        : value(other.value),
          readonlyValue(other.readonlyValue),
          name(other.name)
    {
        CountInstance();
    }

    // Assignment Constructor
    DemoClass& DemoClass::operator=(const DemoClass& other)
    {
        if (this == &other)
            return *this;

        value = other.value;
        readonlyValue = other.readonlyValue;
        name = other.name;

        return *this;
    }

    // Move Constructor
    DemoClass::DemoClass(DemoClass&& other) noexcept
        : value(other.value),
          readonlyValue(other.readonlyValue),
          name(std::move(other.name))
    {
        other.value = 0;
        other.readonlyValue = 0;
        other.name = "moved-from";

        CountInstance();
    }

    // Move Assignment
    DemoClass& DemoClass::operator=(DemoClass&& other) noexcept
    {
        if (this == &other)
            return *this;

        value = other.value;
        readonlyValue = other.readonlyValue;
        name = std::move(other.name);

        other.value = 0;
        other.readonlyValue = 0;
        other.name = "moved-from";

        return *this;
    }

    // ==================================
    // ------------Destructor------------
    // ==================================
    DemoClass::~DemoClass() {
        // nothing to clean up (class has no dynamic memory)
        // but some code like this may be written here
        // delete[] dataArray;
        // delete dataPtr;
    }


    // ==================================
    // --------Getters / Setters---------
    // ==================================
    void DemoClass::setValue(int v) {
        if (v >= 0) value = v;
    }


    // ==================================
    // -------------Methods--------------
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
} // namespace Demo