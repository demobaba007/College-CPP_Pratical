#include <iostream>
using namespace std;

class Circle {
    double radius;

public:
    // Default constructor
    Circle() {
        radius = 0;
    }

    // Parameterized constructor
    Circle(double r) {
        radius = r;
    }

    // Copy constructor
    Circle(const Circle &c) {
        radius = c.radius;
    }

    // Function to set radius
    void setRadius(double r) {
        radius = r;
    }

    // Function to calculate area
    double area() {
        return 3.14159 * radius * radius;
    }

    // Function to calculate circumference
    double circumference() {
        return 2 * 3.14159 * radius;
    }

    // Function to print area and circumference
    void print() {
        cout << "Radius: " << radius << "\n";
        cout << "Area: " << area() << "\n";
        cout << "Circumference: " << circumference() << "\n";
    }
};

int main() {
    Circle c1; // default constructor
    c1.setRadius(5);
    c1.print();

    Circle c2(10); // parameterized constructor
    c2.print();

    Circle c3 = c2; // copy constructor
    c3.print();

    return 0;
}
