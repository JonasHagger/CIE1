#include "DemoClass.h"
#include <utility>   // for std::move

using namespace Demo;

int main() {

    // --- 1: User-defined Constructor ---
    DemoClass a(5, 10);
    std::cout << "\nCreated object a with (5,10)\n";
    a.PrintInfo();


    // --- 2: Default Constructor ---
    DemoClass b;
    std::cout << "\nCreated object b with default constructor\n";
    b.PrintInfo();


    // Modify b to see changes later
    b.setValue(20);


    // --- 3: Copy Constructor ---
    DemoClass c = a;   // same as DemoClass c(a);
    std::cout << "\nCreated object c via copy constructor from a\n";
    c.PrintInfo();


    // --- 4: Copy Assignment Operator ---
    c = b;
    std::cout << "\nAssigned c = b via copy assignment operator\n";
    c.PrintInfo();


    // --- 5: Move Constructor ---
    DemoClass d = std::move(a);
    std::cout << "\nCreated object d via move constructor from a\n";
    d.PrintInfo();

    std::cout << "\nState of 'a' after move:\n";
    a.PrintInfo();


    // --- 6: Move Assignment Operator ---
    d = std::move(b);
    std::cout << "\nAssigned d = std::move(b) via move assignment operator\n";
    d.PrintInfo();

    std::cout << "\nState of 'b' after move:\n";
    b.PrintInfo();


    // --- 7: Show statistics ---
    std::cout << "\nFinal Statistics:\n";
    DemoClass::PrintStatistics();

    return 0;
}