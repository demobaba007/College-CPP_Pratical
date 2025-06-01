#include <iostream>
using namespace std;

int main() {
    string text;
    int counts[26] = {0};

    cout << "Enter text: ";
    getline(cin, text);

    for (char c : text) {
        if (c >= 'A' && c <= 'Z') {
            counts[c - 'A']++;
        } else if (c >= 'a' && c <= 'z') {
            counts[c - 'a']++;
        }
    }

    cout << "Letter\tCount\n";
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << "\t" << counts[i] << "\n";
    }

    return 0;
}
