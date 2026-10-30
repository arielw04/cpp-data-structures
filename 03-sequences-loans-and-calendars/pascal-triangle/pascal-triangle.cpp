#include <iostream>

int main() {
    int r;

    // Prompt user for input
    while (true) {
        std::cout << "Enter rows: ";
        std::cin >> r;
        if (r > 0) {
            break;
        }
        else {
            std::cout << "ERROR: invalid rows! try again!" << std::endl;
        }
    }

    // Create Pascal's Triangle
    int pascal[50][50]; 

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0 || j == i) {
                pascal[i][j] = 1;
            }
            else {
                pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
            }
        }
    }

    // Display Pascal's Triangle
    std::cout << "Pascal’s triangle with " << r << " rows looks like:" << std::endl;
    for (int i = 0; i < r; ++i) {
        // Print leading spaces for alignment
        for (int space = 0; space < r - i - 1; ++space) {
            std::cout << " ";
        }
        for (int j = 0; j <= i; ++j) {
            std::cout << pascal[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}