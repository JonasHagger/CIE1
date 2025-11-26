#include "DemoClass.h"

using namespace Demo;

int main() {
    DemoClass a(5, 10);
    DemoClass b;

    a.Increase(3);
    b.setValue(20);

    a.PrintInfo();
    b.PrintInfo();

    DemoClass::PrintStatistics();
}
