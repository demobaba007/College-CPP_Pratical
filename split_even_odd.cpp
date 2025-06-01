#include <iostream>
using namespace std;

// Function to split array into even and odd arrays
void splitEvenOdd(int arr[], int n, int even[], int &evenCount, int odd[], int &oddCount) {
    evenCount = 0;
    oddCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            even[evenCount++] = arr[i];
        } else {
            odd[oddCount++] = arr[i];
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int even[100], odd[100];
    int evenCount, oddCount;

    splitEvenOdd(arr, n, even, evenCount, odd, oddCount);

    cout << "Even elements:\n";
    for (int i = 0; i < evenCount; i++) {
        cout << even[i] << " ";
    }
    cout << "\n";

    cout << "Odd elements:\n";
    for (int i = 0; i < oddCount; i++) {
        cout << odd[i] << " ";
    }
    cout << "\n";

    return 0;
}
