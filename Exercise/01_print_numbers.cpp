#include <iostream>
#include <iomanip>   // for setw
#include <algorithm> // for min, max
using namespace std;

// Function to compute the value at (row, col) in an n x n spiral
int spiralValue(int n, int row, int col) {
    // Determine which layer the position is in
    int layer = min(min(row, col), min(n - row + 1, n - col + 1)) - 1;

    // Side length of this layer
    int len = n - 2 * layer;

    // Starting value of this layer
    int start = 1 + (n * n - (len * len));

    // Offset within the layer
    int offset = 0;
    if (row == layer + 1) { // top edge
        offset = col - layer - 1;
    } else if (col == n - layer) { // right edge
        offset = (len - 1) + (row - layer - 1);
    } else if (row == n - layer) { // bottom edge
        offset = 2 * (len - 1) + (n - layer - col);
    } else { // left edge
        offset = 3 * (len - 1) + (n - layer - row);
    }

    return start + offset;
}

int main() {
    int n;
    cout << "Enter spiral size n: ";
    cin >> n;
    cout << endl;

    // Print spiral
    for (int r = 1; r <= n; ++r) {
        for (int c = 1; c <= n; ++c) {
            cout << setw(4) << spiralValue(n, r, c);
        }
        cout << endl;
    }

    return 0;
}
