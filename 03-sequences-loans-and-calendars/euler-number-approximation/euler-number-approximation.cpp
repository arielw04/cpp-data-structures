#include <iostream>

int main() {
    int k;
    double e_approx = 1.0;

    while (true) {
        std::cout << "Enter the order you want to approximate e: ";
        std::cin >> k;
        if (k >= 1) {
            break;
        }
        else {
            std::cout << "ERROR: invalid input! try again!" << std::endl;
        }
    }

    double factorial = 1.0;
    for (int i = 1; i < k; ++i) {
        factorial *= i;
        e_approx += 1 / factorial;
    }

    std::cout << "Approximate e with order of " << k << " is: " << e_approx << std::endl;

    return 0;
}