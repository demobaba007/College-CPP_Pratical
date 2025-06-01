#include <iostream>
#include <fstream>
#include <string>
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

    string word;
    while (inFile >> word) {
        outFile << word << "\n";
    }

    inFile.close();
    outFile.close();

    cout << "File copied successfully with new lines after each string.\n";

    return 0;
}
