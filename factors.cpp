#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to print all factors of a number
void printFactors(int num) {
    cout << "Factors of " << num << " are: ";
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

// Function to print prime factors of a number
void printPrimeFactors(int num) {
    cout << "Prime factors of " << num << " are: ";
    for (int i = 2; i <= num; i++) {
        while (num % i == 0 && isPrime(i)) {
            cout << i << " ";
            num /= i;
        }
    }
    cout << "\n";
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    printFactors(num);
    printPrimeFactors(num);

    return 0;
}
