#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}
    Person(string n, int a) : name(n), age(a) {}

    virtual void display() {
        cout << "Name: " << name << "\\n";
        cout << "Age: " << age << "\\n";
    }
};

class Student : public Person {
    string course;
    int marks;
    int year;

public:
    Student() : Person(), course(""), marks(0), year(0) {}
    Student(string n, int a, string c, int m, int y) : Person(n, a), course(c), marks(m), year(y) {}

    void display() override {
        Person::display();
        cout << "Course: " << course << "\\n";
        cout << "Marks: " << marks << "\\n";
        cout << "Year: " << year << "\\n";
    }
};

class Employee : public Person {
    string department;
    double salary;

public:
    Employee() : Person(), department(""), salary(0) {}
    Employee(string n, int a, string d, double s) : Person(n, a), department(d), salary(s) {}

    void display() override {
        Person::display();
        cout << "Department: " << department << "\\n";
        cout << "Salary: " << salary << "\\n";
    }
};

int main() {
    Person *p;

    Student s("Alice", 20, "Computer Science", 85, 2);
    Employee e("Bob", 30, "HR", 50000);

    p = &s;
    cout << "Student details:\\n";
    p->display();

    cout << "\\n";

    p = &e;
    cout << "Employee details:\\n";
    p->display();

    return 0;
}
