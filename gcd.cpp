#include <iostream>
using namespace std;

// Recursive function to calculate GCD
int gcdRecursive(int a, int b) {
    if (b == 0)
        return a;
    return gcdRecursive(b, a % b);
}

// Iterative function to calculate GCD
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD (recursive): " << gcdRecursive(a, b) << "\n";
    cout << "GCD (iterative): " << gcdIterative(a, b) << "\n";

    return 0;
}
