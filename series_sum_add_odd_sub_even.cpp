/*series of : 1 - 2 + 3 - 4 + 5 ........*/
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of terms (n): ";
    cin >> n;

    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double term = 1.0 / pow(i, i);
        if (i % 2 == 0) {
            term = -term;
        }
        sum += term;
    }

    cout << "Sum of the series up to " << n << " terms is: " << sum << endl;

    return 0;
}
