#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int newSize = 0;
    int temp[100];

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < newSize; j++) {
            if (arr[i] == temp[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[newSize++] = arr[i];
        }
    }

    cout << "Array after removing duplicates:\n";
    for (int i = 0; i < newSize; i++) {
        cout << temp[i] << " ";
    }
    cout << "\n";

    return 0;
}
