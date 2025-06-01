#include <iostream>
using namespace std;

// Function to find min, max and average
void findMinMaxAvg(int arr[], int n) {
    int minVal = arr[0];
    int maxVal = arr[0];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minVal) minVal = arr[i];
        if (arr[i] > maxVal) maxVal = arr[i];
        sum += arr[i];
    }
    double avg = (double)sum / n;
    cout << "Minimum: " << minVal << "\n";
    cout << "Maximum: " << maxVal << "\n";
    cout << "Average: " << avg << "\n";
}

// Linear search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1;
}

// Bubble sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary search (array must be sorted)
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        else if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// Display addresses of array elements
void displayAddresses(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Address of element " << i << " (" << arr[i] << "): " << &arr[i] << "\n";
    }
}

// Remove duplicates from array, returns new size
int removeDuplicates(int arr[], int n) {
    if (n == 0 || n == 1) return n;
    bubbleSort(arr, n);
    int j = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }
    return j + 1;
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int arr[100]; // fixed size for simplicity
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Find min, max and average\n";
        cout << "2. Linear search\n";
        cout << "3. Binary search\n";
        cout << "4. Display addresses of elements\n";
        cout << "5. Remove duplicates\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                findMinMaxAvg(arr, n);
                break;
            case 2: {
                int key;
                cout << "Enter element to search (linear): ";
                cin >> key;
                int index = linearSearch(arr, n, key);
                if (index != -1)
                    cout << "Element found at index " << index << "\n";
                else
                    cout << "Element not found\n";
                break;
            }
            case 3: {
                int key;
                cout << "Enter element to search (binary): ";
                cin >> key;
                // Sort array before binary search
                bubbleSort(arr, n);
                int index = binarySearch(arr, n, key);
                if (index != -1)
                    cout << "Element found at index " << index << " (in sorted array)\n";
                else
                    cout << "Element not found\n";
                break;
            }
            case 4:
                displayAddresses(arr, n);
                break;
            case 5:
                n = removeDuplicates(arr, n);
                cout << "Duplicates removed. New array:\n";
                for (int i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << "\n";
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
