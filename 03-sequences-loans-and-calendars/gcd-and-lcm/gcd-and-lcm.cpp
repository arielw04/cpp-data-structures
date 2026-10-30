#include <iostream>

// Function to compute the GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to compute the LCM
int lcm(int a, int b, int gcd) {
    return (a * b) / gcd;
}

int main() {
    int a, b;

    // Prompt user for input
    while (true) {
        std::cout << "Enter two numbers a and b: ";
        std::cin >> a >> b;
        if (a > 0 && b > 0) {
            break;
        }
        else {
            std::cout << "ERROR: invalid inputs! try again!" << std::endl;
        }
    }

    // Compute GCD and LCM
    int gcd_result = gcd(a, b);
    int lcm_result = lcm(a, b, gcd_result);

    // Print results
    std::cout << "GCD(a, b) = " << gcd_result << std::endl;
    std::cout << "LCM(a, b) = " << lcm_result << std::endl;

    return 0;
}