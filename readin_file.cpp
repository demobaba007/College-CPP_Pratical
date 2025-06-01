#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream file("country.txt");
    char country[100];
    while(file >> country) {
        cout << country << endl;
    }
    file.close();
}