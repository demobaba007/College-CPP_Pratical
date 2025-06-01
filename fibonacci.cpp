#include <iostream>
using namespace std;

// Function to generate the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cout << "Enter the number of Fibonacci elements to generate: ";
    cin >> n;

    cout << "First " << n << " Fibonacci numbers:\n";
    for (int i = 1; i <= n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << "\n";

    return 0;
}
