#include <iostream>

void transposeMatrix(int** original, int rows, int cols, int** transposed) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transposed[j][i] = original[i][j];
        }
    }
}

int main() {
    int rows, cols;

    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;

    // Dynamically allocate memory for the original matrix
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    std::cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cin >> matrix[i][j];
        }
    }

    // Dynamically allocate memory for the transposed matrix
    int** transposed = new int* [cols];
    for (int i = 0; i < cols; ++i) {
        transposed[i] = new int[rows];
    }

    // Transpose the matrix
    transposeMatrix(matrix, rows, cols, transposed);

    std::cout << "Original matrix:\n";
    for (int i = 0; i < rows; ++i) {
        std::cout << "[";
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j];
            if (j < cols - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    std::cout << "Transposed matrix:\n";
    for (int i = 0; i < cols; ++i) {
        std::cout << "[";
        for (int j = 0; j < rows; ++j) {
            std::cout << transposed[i][j];
            if (j < rows - 1) std::cout << ", ";
        }
        std::cout << "]\n";
    }

    // Free allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    for (int i = 0; i < cols; ++i) {
        delete[] transposed[i];
    }
    delete[] transposed;

    return 0;
}
