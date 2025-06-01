#include <iostream>
using namespace std;

void printAddresses(char* str) {
    int i = 0;
    while (*(str + i) != '\\0') {
        cout << "Address of character '" << *(str + i) << "' is: " << (void*)(str + i) << "\\n";
        i++;
    }
}

void concatenate(char* str1, char* str2) {
    int i = 0;
    while (*(str1 + i) != '\\0') i++;
    int j = 0;
    while (*(str2 + j) != '\\0') {
        *(str1 + i) = *(str2 + j);
        i++; j++;
    }
    *(str1 + i) = '\\0';
}

int compareStrings(char* str1, char* str2) {
    int i = 0;
    while (*(str1 + i) != '\\0' && *(str2 + i) != '\\0') {
        if (*(str1 + i) != *(str2 + i)) {
            return *(str1 + i) - *(str2 + i);
        }
        i++;
    }
    return *(str1 + i) - *(str2 + i);
}

int stringLength(char* str) {
    int len = 0;
    while (*(str + len) != '\\0') len++;
    return len;
}

void toUpperCase(char* str) {
    int i = 0;
    while (*(str + i) != '\\0') {
        if (*(str + i) >= 'a' && *(str + i) <= 'z') {
            *(str + i) = *(str + i) - 'a' + 'A';
        }
        i++;
    }
}

void reverseString(char* str) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = temp;
    }
}

void insertString(char* str1, char* str2, int pos) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    if (pos > len1) pos = len1;

    for (int i = len1 - 1; i >= pos; i--) {
        *(str1 + i + len2) = *(str1 + i);
    }
    for (int i = 0; i < len2; i++) {
        *(str1 + pos + i) = *(str2 + i);
    }
    *(str1 + len1 + len2) = '\\0';
}

int main() {
    char str1[200], str2[100];
    int choice, pos;

    do {
        cout << "\\nMenu:\\n";
        cout << "1. Print address of each character in a string\\n";
        cout << "2. Concatenate two strings\\n";
        cout << "3. Compare two strings\\n";
        cout << "4. Calculate length of a string\\n";
        cout << "5. Convert lowercase to uppercase\\n";
        cout << "6. Reverse a string\\n";
        cout << "7. Insert a string into another at a position\\n";
        cout << "8. Exit\\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter string: ";
                cin.getline(str1, 200);
                printAddresses(str1);
                break;
            case 2:
                cout << "Enter first string (max 200 chars): ";
                cin.getline(str1, 200);
                cout << "Enter second string (max 100 chars): ";
                cin.getline(str2, 100);
                concatenate(str1, str2);
                cout << "Concatenated string: " << str1 << "\\n";
                break;
            case 3:
                cout << "Enter first string: ";
                cin.getline(str1, 200);
                cout << "Enter second string: ";
                cin.getline(str2, 100);
                {
                    int res = compareStrings(str1, str2);
                    if (res == 0) cout << "Strings are equal\\n";
                    else if (res < 0) cout << "First string is less than second string\\n";
                    else cout << "First string is greater than second string\\n";
                }
                break;
            case 4:
                cout << "Enter string: ";
                cin.getline(str1, 200);
                cout << "Length of string: " << stringLength(str1) << "\\n";
                break;
            case 5:
                cout << "Enter string: ";
                cin.getline(str1, 200);
                toUpperCase(str1);
                cout << "Uppercase string: " << str1 << "\\n";
                break;
            case 6:
                cout << "Enter string: ";
                cin.getline(str1, 200);
                reverseString(str1);
                cout << "Reversed string: " << str1 << "\\n";
                break;
            case 7:
                cout << "Enter first string (max 200 chars): ";
                cin.getline(str1, 200);
                cout << "Enter string to insert (max 100 chars): ";
                cin.getline(str2, 100);
                cout << "Enter position to insert at (0-based index): ";
                cin >> pos;
                cin.ignore();
                insertString(str1, str2, pos);
                cout << "String after insertion: " << str1 << "\\n";
                break;
            case 8:
                cout << "Exiting...\\n";
                break;
            default:
                cout << "Invalid choice. Try again.\\n";
        }
    } while (choice != 8);

    return 0;
}
