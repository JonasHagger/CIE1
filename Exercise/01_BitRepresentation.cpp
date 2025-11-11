#include <iostream>
#include <climits> // for INT_MIN, INT_MAX
using namespace std;

int main() {
    // Get system byte size for int
    size_t numBytes = sizeof(int);
    size_t numBits = numBytes * 8;

    cout << "An 'int' on this system uses " << numBytes << " bytes (" << numBits << " bits)." << endl;
    cout << "Valid range: [" << INT_MIN << ", " << INT_MAX << "]" << endl;
    cout << endl;

    // User input
    int number;
    cout << "Input integer number: ";
    cin >> number;

    cout << "Bit representation is: ";

    // Print bits in Little Endian (least significant bit first)
    for (size_t i = 0; i < numBits; ++i) {
        cout << ((number >> i) & 1);

        // Add space after each 8 bits
        if ((i + 1) % 8 == 0) cout << " ";
    }

    // Add sign bit at the end (0 = positive, 1 = negative)
    int signBit = (number < 0) ? 1 : 0;
    cout << signBit << endl;

    return 0;
}
