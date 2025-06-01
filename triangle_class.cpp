#include <iostream>
#include <cmath>
using namespace std;

class Triangle {
    double a, b, c;

    bool isValid() {
        return (a > 0 && b > 0 && c > 0) &&
               (a + b > c) && (a + c > b) && (b + c > a);
    }

public:
    Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {
        if (!isValid()) {
            cout << "Invalid triangle sides provided. Setting sides to 1,1,1 by default.\n";
            a = b = c = 1;
        }
    }

    // Area of right angled triangle (assuming a and b are perpendicular sides)
    double area(double base, double height) {
        return 0.5 * base * height;
    }

    // Area using Heron's formula
    double area() {
        double s = (a + b + c) / 2.0;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    void display() {
        cout << "Sides: " << a << ", " << b << ", " << c << "\n";
        cout << "Area (Heron's formula): " << area() << "\n";
        cout << "Area (right angled, base=a, height=b): " << area(a, b) << "\n";
    }
};

int main() {
    Triangle t1(3, 4, 5);
    t1.display();

    Triangle t2(1, 2, 3); // invalid triangle, will reset to 1,1,1
    t2.display();

    return 0;
}
