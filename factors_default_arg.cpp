#include <iostream>
using namespace std;

// Function to print factors of a number with default argument
void printFactors(int num = 10) {
    cout << "Factors of " << num << " are: ";
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            cout << i << " ";
        }
    }
    cout << "\n";
}

int main() {
    int num;
    cout << "Enter a number (or press enter to use default 10): ";
    if (!(cin >> num)) {
        cin.clear();
        cin.ignore();
        cout << "Using default number 10.\n";
        printFactors();
    } else {
        printFactors(num);
    }

    return 0;
}
