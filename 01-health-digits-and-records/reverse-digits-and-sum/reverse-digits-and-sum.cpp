#include <iostream>
#include <iomanip>

int main() {
    int number, reversed_number = 0, sum_of_digits = 0;

    std::cout << "Please enter a number (1000-9999): ";
    std::cin >> number;

    // Check if the input is within the valid range
    if (number < 1000 || number > 9999) {
        std::cout << "Error: Number must be between 1000 and 9999." << std::endl;
        return 1; // Exit with an error code
    }

    // Extract and reverse digits
    int temp = number;
    for (int i = 0; i < 4; ++i) {
        int digit = temp % 10;
        reversed_number = reversed_number * 10 + digit;
        sum_of_digits += digit;
        temp /= 10;
    }

    // Output results with proper formatting
    std::cout << "Number of reversed digits: " << std::setw(4) << std::setfill('0') << reversed_number << "\n";
    std::cout << "Sum of the digits: " << sum_of_digits << "\n";

    return 0;
}