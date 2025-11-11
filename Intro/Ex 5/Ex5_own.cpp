#include <iostream>
#include <vector>

std::vector<float> get_array() {
    int array_size;
    std::cout << "Define size of Array: ";
    std::cin >> array_size;

    std::vector<float> array(array_size);
    for (int i = 0; i < array_size; ++i) {
        std::cout << "Enter array element " << i << ": ";
        std::cin >> array[i];
    }
    return array;
}

int main() {
    std::vector<float> numbers = get_array();

    std::cout << "You entered:\n";
    for (float n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    // handle empty or single-element vector
    if (numbers.size() > 1) {
        // bubble sort
        for (std::size_t pass = 0; pass < numbers.size() - 1; ++pass) {
            bool swapped = false;
            for (std::size_t i = 0; i < numbers.size() - 1 - pass; ++i) {
                if (numbers[i] > numbers[i + 1]) {
                    std::swap(numbers[i], numbers[i + 1]);
                    swapped = true;
                }
            }
            if (!swapped) break; // already sorted
        }
    }

    std::cout << "Numbers sorted: ";
    for (float n : numbers) std::cout << n << " ";
    std::cout << std::endl;

    return 0;
}
