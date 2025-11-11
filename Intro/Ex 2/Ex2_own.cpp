#include <iostream>
#include <cmath>
#include <tuple>

float input_param() {
    float param;

    std::cout << "Enter Value: " << std::endl;
    std::cin >> param;
    return param;
}

bool check_0(int param) {
    if (param == 0) {
        return true;
    }
    else {
        return false;
    }
}

std::tuple<float, float, bool> comp_discriminant(float a, float b, float c) {
    // compute discriminant
    float discriminant = (b * b - 4 * a * c) / (4 * a * a);
    std::cout << "The discriminante is: " << discriminant << "\n";

    // initialize x1 and x2 and if solution is complex or not
    float x1, x2;
    bool is_complex;

    // get solution
    if (discriminant < 0) {
        x1 = -(b / (2*a)) + std::sqrt(- discriminant);
        x2 = -(b / (2*a)) - std::sqrt(- discriminant);
        is_complex = true;
    }
    else if (discriminant == 0) {
        x1 = -(b / (2*a));
        x2 = x1;
        is_complex = false;
    }
    else {
        x1 = -(b / (2*a)) + std::sqrt(discriminant);
        x2 = -(b / (2*a)) - std::sqrt(discriminant);
        is_complex = false;
    }
    return {x1, x2, is_complex};
}


int main() {
    // init values
    float a, b, c;

    // input values from user
    std::cout << "Value for a\n";
    a = input_param();
    std::cout << "Value for b\n";
    b = input_param();
    std::cout << "Value for c\n";
    c = input_param();

    // calc and prompt solution
    if (check_0(a)) {
        if (check_0(b)) {
            if (check_0(c)) {
                std::cout << "Every number is a solution";
            }
            else {
                std::cout << "There is no solution";
            }
        }
        else {
            std::cout << "One solution x1=x2=" << -c / b;
        }
    }
    else {
        auto [x1, x2, is_complex] = comp_discriminant(a, b, c);
        if (is_complex) {
            std::cout << "WRONG CALCULATION!!!! \n" << std::endl;
            std::cout << "The solution is: " << x1 << "i, " << x2 << "i" << std::endl;
        }
        else {
            std::cout << "The solution is: " << x1 << ", " << x2 << std::endl;
        }
    }
    return 0;
}