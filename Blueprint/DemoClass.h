#pragma once
#include <string>
#include <iostream>

namespace Demo {
    class DemoClass {
    private:
        int value;
        int readonlyValue;
        std::string name = "DefaultName";

        static int instanceCounter;
        static int totalCreatedObjects;

        static void CountInstance();

    public:
        // Constructors
        DemoClass(int initialValue, int readOnly);
        DemoClass();
        
        // Destructor
        ~DemoClass();

        // Getters / Setters
        int getValue() const { return value; }
        void setValue(int v);

        int getReadonlyValue() const { return readonlyValue; }

        std::string getName() const { return name; }
        void setName(const std::string& n) { name = n; }

        // Methods
        void Increase(int amount);
        void PrintInfo() const;

        // Static
        static void PrintStatistics();
    };
} // namespace Demo