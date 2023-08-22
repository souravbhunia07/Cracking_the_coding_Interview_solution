#include <iostream>
using namespace std;

// TC =  O(log n)

int recursiveMultiply(int a, int b) {
    if (b == 0) {
        return 0;
    }

    // >> ->  Divide , << -> Multiply

    int result = recursiveMultiply(a, b >> 1) << 1; // Multiply by 2
    if (b & 1) {
        result += a; // Add a when b is odd
    }

    return result;
}

int main() {
    int a = 3;
    int b = 9;

    int result = recursiveMultiply(a, b);

    cout << a << " * " << b << " = " << result << endl;

    return 0;
}
