// Include standard in- and output and math libraries
#include <iostream>
#include <cmath>

int main()
{
    // Declare variables and start user input
    double a, b, c;

    std::cout << "Computing solution for quadratic equation a x^2 + b^x + c = 0.\n\nInput coefficients:\n  a = ";

    std::cin >> a;

    std::cout << "  b = ";
    std::cin >> b;

    std::cout << "  c = ";
    std::cin >> c;

    std::cout << std::endl;

    // If we have a quadratic equation
    if (a != 0.0)
    {
        double discriminant = (b * b - 4.0 * a * c) / (4.0 * a * a);

        if (discriminant > 0)
        {
            double x1 = -b / (2.0 * a) + std::sqrt(discriminant);
            double x2 = -b / (2.0 * a) - std::sqrt(discriminant);

            std::cout << "Two real solutions:" << std::endl;
            std::cout << "  x1 = " << x1 << "\n  x2 = " << x2 << std::endl;
        }
        else if (discriminant < 0.0)
        {
            double xr = -b / (2.0 * a);
            double xi = std::sqrt(-discriminant);

            std::cout << "Two complex solutions:" << std::endl;
            std::cout << "  x1 = " << xr << " + i * " << xi << std::endl;
            std::cout << "  x2 = " << xr << " - i * " << xi << std::endl;
        }
        else
        {
            double x1 = -b / (2.0 * a);
            std::cout << "One real solution: " << x1 << std::endl;
        }
    }
    else // just a linear equation
    {
        if (b != 0.0)
        {
            std::cout << "One real solution: x1 = " << -c / b << std::endl;
        }
        else // a == 0, b == 0
        {
            if (c != 0)
            {
                std::cout << "No solution!" << std::endl;
            }
            else // a == 0, b == 0, c == 0
            {
                std::cout << "Every number is a solution!" << std::endl;
            }
        }
    }
}