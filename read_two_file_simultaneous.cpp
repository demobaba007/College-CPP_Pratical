#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main(){
    const int SIZE = 100;
    char line[SIZE];
    ifstream fin1, fin2;
    fin1.open("country.txt");
    fin2.open("capital.txt");
    for (int i = 1; i <= 10; i++) {
        if (fin1.eof() != 0){
            cout << "Exit from country\n";
            exit(1);
        }
        fin1.getline(line, SIZE);
        cout << "Capital of " << line;

        if (fin2.eof() != 0){
            cout << "Exit from capital\n";
            exit(1);
        }
        fin2.getline(line, SIZE);
        cout << " is " <<line << endl;
    }
}