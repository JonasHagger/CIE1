#include <iostream>

#include <iostream>

int add(int a, int b) {
    return a + b;
}

void print(int sum) {
    std::cout << "Sum is " << sum << std::endl;
}

int main() {

    // Define and initialize
    int mdArray[3][6] = {
        {92, 97, 98, 99, 98, 94},
        {1, 2, 3, 4, 5, 6},
        {0, 101, 0, -101, 0, 101}
    };

    // Take input from the user
    std::cin >> mdArray [2][3];

    // print values with for-loop
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 6; ++j) {
            std::cout << mdArray[i][j] << " ";
        }
        std::cout << std::endl;
    }

    double score = 3.9;

    if (score == 4.0) {
        std::cout << "Knappe Nummer Bruder";
    }
    else if (score >= 4.0) {
        std::cout << "f";
    }
    else {
        std::cout << "Streber";
    }

    int sum = add(1 , 2);
    print(sum);

    return 0;
}