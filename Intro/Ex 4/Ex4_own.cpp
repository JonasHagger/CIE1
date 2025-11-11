#include <cmath>
#include <iostream>

float solve_f_x (float x) {
    // 𝑓 𝑥 = (𝑥 + 1)(𝑥 − 1)
    float f_x = (x +1) * (x - 1);
    return f_x;
}

float solve_u_i(float a, float b) {
    float f_a = solve_f_x(a);
    float f_b = solve_f_x(b);
    float u_i = a - (f_a * (b - a))/(f_b - f_a);
    return u_i;
}

int main() {
    float a,b; // init interval values
    bool right_entry = false; // init entry checker

    // for loop for right entry of param
    while (right_entry == false) {
        std::cout << "Please enter the Intervalborders." << std::endl;
        std::cout << "a: ";
        std::cin >> a;
        std::cout << std::endl;
        std::cout << "b: ";
        std::cin >> b;
        std::cout << std::endl;

        // check if 𝑓(𝑎) ⋅ 𝑓(𝑏) < 0
        float product = solve_f_x(a) * solve_f_x(b);
        if (product < 0) {
            std::cout << "Correct interval! f(a) * f(b)= " << product << std::endl;
            right_entry = true;
        }
        else {
            std::cout << "Wrong interval! f(a) * f(b)= " << product << std::endl;
            right_entry = false;

        }
    }

    //input tolerance eps
    float eps;
    std::cout << "Please enter the tolerance." << std::endl;
    std::cout << "eps: ";
    std::cin >> eps;
    std::cout << std::endl;

    // get u_i and f(u_i)
    float u_i = solve_u_i(a, b);
    float f_u_i = solve_f_x(u_i);

    //calc tolerance
    float difference_to_0 = std::sqrt(f_u_i * f_u_i);
    std::cout << "difference to 0 is: " << difference_to_0 << std::endl;

    int counter = 0; //init counter
    // loop
    while (difference_to_0 > eps){
        std::cout << "Iteration " << counter << std::endl;
        // check if 𝑓(u_i) ⋅ 𝑓(a) < 0
        float product_iterativ = f_u_i * solve_f_x(a);
        std::cout << "f(u_i) * f(a)= " << product_iterativ << std::endl;
        if (product_iterativ < 0) {
            std::cout << "b was: " << b << "! b is being updated to: " << u_i << std::endl;
            b = u_i;
            std::cout << "b is: " << b << std::endl;
        }
        else {
            std::cout << "a was: " << a << "! a is being updated to: " << u_i << std::endl;
            a = u_i;\
            std::cout << "a is: " << a << std::endl;
        }

        // get new u_i and new f(u_i)
        u_i = solve_u_i(a, b);
        f_u_i = solve_f_x(u_i);

        //calc new tolerance
        difference_to_0 = std::sqrt(f_u_i * f_u_i);
        std::cout << "difference to 0 is: " << difference_to_0 << std::endl;

        //add counter
        counter++;
    }

    std::cout << "The solution is u= " << u_i << "! With f(u)= "<< f_u_i << std::endl;
    return 0;
}