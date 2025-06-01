#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int rollNo;
    char name[50];
    char className[20];
    int year;
    int totalMarks;

    void input() {
        cout << "Enter roll no: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter name: ";
        cin.getline(name, 50);
        cout << "Enter class: ";
        cin.getline(className, 20);
        cout << "Enter year: ";
        cin >> year;
        cout << "Enter total marks: ";
        cin >> totalMarks;
        cin.ignore();
    }

    void display() {
        cout << "Roll No: " << rollNo << "\n";
        cout << "Name: " << name << "\n";
        cout << "Class: " << className << "\n";
        cout << "Year: " << year << "\n";
        cout << "Total Marks: " << totalMarks << "\n";
        cout << "-------------------------\n";
    }
};

int main() {
    Student students[5];
    fstream file("students.dat", ios::out | ios::binary);

    cout << "Enter details of 5 students:\n";
    for (int i = 0; i < 5; i++) {
        students[i].input();
        file.write((char*)&students[i], sizeof(Student));
    }
    file.close();

    file.open("students.dat", ios::in | ios::binary);
    cout << "\nStudent records from file:\n";
    for (int i = 0; i < 5; i++) {
        file.read((char*)&students[i], sizeof(Student));
        students[i].display();
    }
    file.close();

    return 0;
}
