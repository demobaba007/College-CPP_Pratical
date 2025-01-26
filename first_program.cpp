/*Sum of first n terms of series 1-2+3-4+5......*/

// #include <iostream>
// using namespace std;
// // Function that calculate the main program
// int Sum(int n) {
//     int sum1 = 0;
//     int sum2 = 0;
//     for (int i = 1; i <= n; i++) {
//         if (i % 2 == 0){
//             cout << " - " << i; 
//             sum2 -= i;
//         }else {
//             sum1 += i;
//             cout << " + " << i;
//         }
//     }
//     return sum1 + sum2;
// }

// int main() {
//     int Num;
//     cout << "Enter any number : ";
//     cin >> Num;
//     cout << " = " << Sum(Num);
//     return 0;
// }


/*Sum of first n terms of series 1 + 1/2 + 1/3 + 1/4 + 1/5......*/

// #include <iostream>
// using namespace std;

// float Sum(float n) {
//     float sum1 = 0;
//     for (float i = 1; i <= n; i++) {
//         sum1 += 1/i;
//     }
//     return sum1;
// }

// int main() {
//     float Num;
//     cout << "Enter the number : ";
//     cin >> Num;
//     cout << "1 + 1/2 + 1/3 + 1/4 + .... = " << Sum(Num);
//     return 0;
// }


/*Sum of first n terms of series 1 + 1/2! + 1/3! + 1/4! + 1/5!......*/

// #include <iostream>
// using namespace std;

// float Factorial(int n) {
//     int sum2 = 1;
//     if (n == 0) {
//         return sum2;
//     }else{
//         for (int i = 1; i <= n; i++) {
//             sum2 *= i;
//         }
//         return sum2;
//     }
// }

// float Sum(int num) {
//     float sum1 = 0;
//     for (int i = 1; i <=num; i++) {
//         sum1 += 1 / Factorial(i);
//     }
//     return sum1;
// }

// int main() {
//     int num;
//     cout << "Enter any number : ";
//     cin >> num;
//     cout << "1 + 1/2! + 1/3! + 1/4! = " << Sum(num);
//     return 0;
// }


/*Sum of first n terms of series 1 - 2^n + 3^n - 4^n +......*/

// #include <iostream>
// using namespace std;

// int exponent(int num, int n) {
//     int sum = 1;
//     for (int i = 1; i <= n; i++) {
//         sum *=num;
//     }
//     return sum;
// }

// int Sum(int n) {
//     int sum1 = 0;
//     int sum2 = 0;
//     for (int i = 1; i <= n; i++) {
//         if (i % 2 == 0){
//             sum2 -= exponent(i, n);
//         }else {
//             sum1 += exponent(i, n);
//         }
//     }
//     return sum1 + sum2;
// }

// int main() {
//     int Num;
//     cout << "Enter any number : ";
//     cin >> Num;
//     cout << "1 - 2^n + 3^n - 4^n +...... = " << Sum(Num);
//     return 0;
// }