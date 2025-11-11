// Include the standard input-/output library
#include <iostream>

// Define main function with empty parameter list ( )
int main()
{
    // Define variables for user input
    double a1, a2, a3, a4;

    // Start asking user for input
    std::cout << "Input values:" << std::endl;

    std::cout << "  a1 = ";
    std::cin >> a1;

    std::cout << "  a2 = ";
    std::cin >> a2;

    std::cout << "  a3 = ";
    std::cin >> a3;

    std::cout << "  a4 = ";
    std::cin >> a4;

    // Compute volume
    double v = a1 * a2 * (a3 + a4 / 3.0);

    // Output result to the console
    std::cout << "\nTotal volume of building V = " << v << std::endl;
}