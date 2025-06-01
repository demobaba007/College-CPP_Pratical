#include <iostream>
using namespace std;

class Fraction {
    int numer;
    int denom;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void simplify() {
        int g = gcd(numer, denom);
        numer /= g;
        denom /= g;
        if (denom < 0) { // keep denominator positive
            denom = -denom;
            numer = -numer;
        }
    }

public:
    // Default constructor
    Fraction() : numer(0), denom(1) {}

    // Parameterized constructor
    Fraction(int n, int d) {
        numer = n;
        denom = d == 0 ? 1 : d;
        simplify();
    }

    // Copy constructor
    Fraction(const Fraction &f) {
        numer = f.numer;
        denom = f.denom;
    }

    void display() {
        cout << numer << "/" << denom << "\n";
    }

    Fraction add(const Fraction &f) {
        int n = numer * f.denom + f.numer * denom;
        int d = denom * f.denom;
        return Fraction(n, d);
    }

    Fraction subtract(const Fraction &f) {
        int n = numer * f.denom - f.numer * denom;
        int d = denom * f.denom;
        return Fraction(n, d);
    }

    Fraction multiply(const Fraction &f) {
        int n = numer * f.numer;
        int d = denom * f.denom;
        return Fraction(n, d);
    }

    Fraction divide(const Fraction &f) {
        int n = numer * f.denom;
        int d = denom * f.numer;
        return Fraction(n, d);
    }
};

int main() {
    Fraction f1(1, 2);
    Fraction f2(3, 4);

    cout << "f1 = ";
    f1.display();
    cout << "f2 = ";
    f2.display();

    Fraction sum = f1.add(f2);
    cout << "Sum = ";
    sum.display();

    Fraction diff = f1.subtract(f2);
    cout << "Difference = ";
    diff.display();

    Fraction prod = f1.multiply(f2);
    cout << "Product = ";
    prod.display();

    Fraction quot = f1.divide(f2);
    cout << "Quotient = ";
    quot.display();

    return 0;
}
