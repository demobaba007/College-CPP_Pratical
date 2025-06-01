#include <iostream>
using namespace std;

class Complex {
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Copy constructor
    Complex(const Complex &c) {
        real = c.real;
        imag = c.imag;
    }

    void display() {
        cout << real << " + " << imag << "i\n";
    }

    Complex add(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    Complex subtract(const Complex &c) {
        return Complex(real - c.real, imag - c.imag);
    }

    Complex multiply(const Complex &c) {
        double r = real * c.real - imag * c.imag;
        double i = real * c.imag + imag * c.real;
        return Complex(r, i);
    }

    Complex divide(const Complex &c) {
        double denom = c.real * c.real + c.imag * c.imag;
        double r = (real * c.real + imag * c.imag) / denom;
        double i = (imag * c.real - real * c.imag) / denom;
        return Complex(r, i);
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(1, 4);

    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();

    Complex sum = c1.add(c2);
    cout << "Sum = ";
    sum.display();

    Complex diff = c1.subtract(c2);
    cout << "Difference = ";
    diff.display();

    Complex prod = c1.multiply(c2);
    cout << "Product = ";
    prod.display();

    Complex quot = c1.divide(c2);
    cout << "Quotient = ";
    quot.display();

    return 0;
}
