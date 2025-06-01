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

void printFirstNPrimes(int n) {
    int count = 0;
    int num = 2;
    while (count < n) {
        if (isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << "\n";
}

void printPrimesUpToN(int n) {
    cout << "Prime numbers up to " << n << ":\n";
    for (int num = 2; num <= n; num++) {
        if (isPrime(num)) {
            cout << num << " ";
        }
    }
    cout << "\n";
}

void printNPrimesFromM(int n, int m) {
    int count = 0;
    int num = m;
    cout << n << " prime numbers starting from " << m << ":\n";
    while (count < n) {
        if (isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }
    cout << "\n";
}

int main() {
    cout <<" 1. First n prime numbers\n";
    cout <<" 2. First n prime numbers in a given range\n";
    cout <<" 3. Prime number starting with a given digit and in a given range\n";
    cout <<" 4. Exit\n";
    cout <<"Enter the choice: ";
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout <<"Enter the number of prime numbers you want to see: ";
        int n;
        cin >> n;
        printFirstNPrimes(n);
        break;
    case 2:
        cout <<"Enter the range of numbers you want to see prime numbers in: ";
        int a;
        cin >> a;
        printPrimesUpToN(a);
        break;
    case 3:
        int start, end;
        cout << "Enter the digit you want to start with: ";
        cin >> start;
        cout <<"Enter the digit you want to end with: ";
        cin >> end;
        printNPrimesFromM(start, end);
        break;
    default:
        cout << "Invalid choice. Exiting...\n";
        break;
    }
    return 0;
}
