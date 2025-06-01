#include <iostream>
using namespace std;

class Matrix {
    int rows, cols;
    int data[10][10]; // fixed size for simplicity

public:
    Matrix() : rows(0), cols(0) {}

    void readMatrix() {
        cout << "Enter number of rows (max 10): ";
        cin >> rows;
        cout << "Enter number of columns (max 10): ";
        cin >> cols;
        cout << "Enter elements:\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cin >> data[i][j];
            }
        }
    }

    void printMatrix() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
            cout << "\n";
        }
    }

    bool sum(const Matrix &m, Matrix &result) {
        if (rows != m.rows || cols != m.cols) {
            return false;
        }
        result.rows = rows;
        result.cols = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + m.data[i][j];
            }
        }
        return true;
    }

    bool product(const Matrix &m, Matrix &result) {
        if (cols != m.rows) {
            return false;
        }
        result.rows = rows;
        result.cols = m.cols;
        for (int i = 0; i < result.rows; i++) {
            for (int j = 0; j < result.cols; j++) {
                result.data[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * m.data[k][j];
                }
            }
        }
        return true;
    }

    void transpose(Matrix &result) {
        result.rows = cols;
        result.cols = rows;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[j][i] = data[i][j];
            }
        }
    }
};

int main() {
    Matrix m1, m2, result;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Input first matrix\n";
        cout << "2. Input second matrix\n";
        cout << "3. Sum of matrices\n";
        cout << "4. Product of matrices\n";
        cout << "5. Transpose of first matrix\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        bool success;
        switch (choice) {
            case 1:
                cout << "First matrix:\n";
                m1.readMatrix();
                break;
            case 2:
                cout << "Second matrix:\n";
                m2.readMatrix();
                break;
            case 3:
                success = m1.sum(m2, result);
                if (success) {
                    cout << "Sum of matrices:\n";
                    result.printMatrix();
                } else {
                    cout << "Error: Matrices dimensions do not match for addition.\n";
                }
                break;
            case 4:
                success = m1.product(m2, result);
                if (success) {
                    cout << "Product of matrices:\n";
                    result.printMatrix();
                } else {
                    cout << "Error: Matrices dimensions do not match for multiplication.\n";
                }
                break;
            case 5:
                m1.transpose(result);
                cout << "Transpose of first matrix:\n";
                result.printMatrix();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
