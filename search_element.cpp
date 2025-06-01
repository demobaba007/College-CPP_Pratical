#include <iostream>
using namespace std;

int main() {
    int n, element;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[100];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> element;

    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == element) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        cout << "Element found at position: " << pos << "\n";
    } else {
        cout << "Element not found\n";
    }

    return 0;
}
