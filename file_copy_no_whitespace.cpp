#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string sourceFile, destFile;
    cout << "Enter source file name: ";
    cin >> sourceFile;
    cout << "Enter destination file name: ";
    cin >> destFile;

    ifstream inFile(sourceFile);
    ofstream outFile(destFile);

    if (!inFile) {
        cout << "Error opening source file.\n";
        return 1;
    }
    if (!outFile) {
        cout << "Error opening destination file.\n";
        return 1;
    }

    char ch;
    while (inFile.get(ch)) {
        if (!isspace(static_cast<unsigned char>(ch))) {
            outFile.put(ch);
        }
    }

    inFile.close();
    outFile.close();

    cout << "File copied successfully without whitespaces.\n";

    return 0;
}
