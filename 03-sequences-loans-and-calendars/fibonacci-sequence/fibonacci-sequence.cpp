#include <iostream>

int main() {
    int n;

    // Prompt user for input
    while (true) {
        std::cout << "Enter n: ";
        std::cin >> n;
        if (n >= 0) {
            break;
        }
        else {
            std::cout << "ERROR: invalid n! try again!" << std::endl;
        }
    }

    // Print Fibonacci series
    int a = 0, b = 1;
    std::cout << "Fibonacci sequence up to F(" << n << "): ";

    for (int i = 0; i <= n; ++i) {
        if (i == 0) {
            std::cout << a;
        }
        else if (i == 1) {
            std::cout << ", " << b;
        }
        else {
            int next = a + b;
            std::cout << ", " << next;
            a = b;
            b = next;
        }
    }
    std::cout << std::endl;

    return 0;
}