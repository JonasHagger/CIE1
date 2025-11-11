#include <iostream>
#include <vector>

float v_comp(float a1, float a2, float a3, float a4) {
    float volume = a1 * a2 * (a3 + a4 / 3);
    return volume;
}

float volume_calc_V1() {
    // Declaration
    int n = 4;   //amount of variables
    float a1, a2, a3, a4;
    float a_index;

    // Variable abfragen
    std::cout << "a1:";
    std::cin >> a1;
    std::cout << "a2:";
    std::cin >> a2;
    std::cout << "a3:";
    std::cin >> a3;
    std::cout << "a4:";
    std::cin >> a4;

    // Computation
    float volume = v_comp(a1, a2, a3, a4);
    return volume;
}

std::vector<double> volume_calc_V2() {
    int n = 4;
    std::cout << "How many parameters? ";
    //std::cin >> n;
    std::cout << "-> 4 ";

    std::vector<double> a_values;   // list (vector) to store parameters
    a_values.reserve(n);            // optional, improves performance

    for (int index = 0; index < n; ++index) {
        double a_index;
        std::cout << "a" << index + 1 << ": ";
        std::cin >> a_index;
        a_values.push_back(a_index);  // store the value in the vector
    }
    return a_values;
}

int main() {

    float volume = volume_calc_V1();
    std::vector<double> vector = volume_calc_V2();

    // print to console
    std::cout << "V= " << volume << std::endl;

    // Example: print the stored values
    std::cout << "\nStored parameters:\n";
    for (int i = 0; i < 4; ++i) {
        std::cout << "a" << i + 1 << " = " << vector[i] << "\n";
    }

    return 0;
}