#include <iostream>
using namespace std;
int main() {
    char list[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int number;
    cout << "Enter the any number : ";
    cin >> number;
    for (int i =0; i < number; i++) {
        for (int j = i; j >= 0; j--) {
            cout << list[j] << ' ';
        }
        cout << "\n";
    }
    return 0;
}


