#include <iostream>
#include <fstream>
#include <sstream>
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

    int charCount = 0, wordCount = 0, lineCount = 0;
    string line;

    while (getline(inFile, line)) {
        outFile << line << "\n";
        lineCount++;
        charCount += line.length() + 1; // +1 for newline
        istringstream iss(line);
        string word;
        while (iss >> word) {
            wordCount++;
        }
    }

    inFile.close();
    outFile.close();

    cout << "Total characters copied: " << charCount << "\n";
    cout << "Total words copied: " << wordCount << "\n";
    cout << "Total lines copied: " << lineCount << "\n";

    return 0;
}
