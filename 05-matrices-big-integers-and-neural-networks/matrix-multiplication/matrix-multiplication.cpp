#include <iostream>
using namespace std;

void multiplyMatrices(int** A, int m, int n, int** B, int p, int** C) {
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < p; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    cout << "[";
    for (int i = 0; i < rows; ++i) {
        cout << "[";
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j];
            if (j < cols - 1) cout << ", ";
        }
        cout << "]";
        if (i < rows - 1) cout << ",\n";
    }
    cout << "]\n";
}

int main() {
    int m, n, p;

    // Taking dimensions and elements of matrix A from user
    cout << "Enter A’s number of rows and columns: ";
    cin >> m >> n;
    int** A = new int* [m];
    for (int i = 0; i < m; ++i) {
        A[i] = new int[n];
    }
    cout << "Enter A’s elements:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> A[i][j];
        }
    }

    // Taking dimensions and elements of matrix B from user
    cout << "Enter B’s number of rows and columns: ";
    cin >> n >> p;
    int** B = new int* [n];
    for (int i = 0; i < n; ++i) {
        B[i] = new int[p];
    }
    cout << "Enter B’s elements:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            cin >> B[i][j];
        }
    }

    // Allocate memory for matrix C
    int** C = new int* [m];
    for (int i = 0; i < m; ++i) {
        C[i] = new int[p];
    }

    // Multiply matrices A and B to get matrix C
    multiplyMatrices(A, m, n, B, p, C);

    // Print matrices A, B, and C
    cout << "A is\n";
    printMatrix(A, m, n);

    cout << "B is\n";
    printMatrix(B, n, p);

    cout << "The product of A and B is\n";
    printMatrix(C, m, p);

    // Free allocated memory
    for (int i = 0; i < m; ++i) {
        delete[] A[i];
    }
    delete[] A;

    for (int i = 0; i < n; ++i) {
        delete[] B[i];
    }
    delete[] B;

    for (int i = 0; i < m; ++i) {
        delete[] C[i];
    }
    delete[] C;

    return 0;
}
