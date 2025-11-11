#include <iostream>
#include <cmath>

int main( )
{
    double a, b, eps;

    std::cout << "Interval [a, b]:\n  a = ";
    std::cin >> a;
    std::cout << "  b = ";
    std::cin >> b;

    std::cout << "Tolerance eps: ";
    std::cin >> eps;

    int itmax;
    std::cout << "Input maximum number of iterations: ";
    std::cin >> itmax;

    // Check for initial conditions
    double fa = ( a + 1.0 ) * ( a - 1.0 );
    double fb = ( b + 1.0 ) * ( b - 1.0 );

    if( fa * fb >= 0.0 )
    {
        std::cout << "\nError: Sign of function f is equal at interval limits!"
                  << std::endl;

        return 0;
    }

    for( int iteration = 0; iteration < itmax; iteration++ )
    {
        // Computation of next approximation
        fa = ( a + 1.0 ) * ( a - 1.0 );
        fb = ( b + 1.0 ) * ( b - 1.0 );

        double u = a - fa * ( b - a ) / ( fb - fa );
        double fu = ( u + 1.0 ) * ( u - 1.0 );

        std::cout << "\nafter iteration " << iteration << ": u = " << u
                  << ", with f(u) = " << fu;

        if( fu * fa < 0)
        {
            b = u;
        }
        else
        {
            a = u;
        }

        if( std::abs( fu ) < eps )
        {
            std::cout << "\n\nSolution converged after " << iteration << " iterations "
                      << "with x0 = " << u << " and f(x0) = " << fu << std::endl;

            return 0;
        }
    }

    std::cout << "\n\nError: Solution did not converge within a maximum of "
              << itmax << " iterations!" << std::endl;
}