#include <iostream>
#include <cmath>

static bool is_armstrong(int num) {
    int sum = 0, temp = num, digits = 0;

    
    while (temp > 0) {
        ++digits;
        temp /= 10;
    }

    temp = num;
    while (temp > 0) {
        sum += pow(temp % 10, digits);
        temp /= 10;
    }

    return num == sum;
}

int main() {
    int lb, ub;
    while (true) {
        std::cout << "Enter left bound of the range (lb): ";
        std::cin >> lb;
        std::cout << "Enter right bound of the range (ub): ";
        std::cin >> ub;
        if (lb >= 0 && lb < ub) {
            break;
        }
        else {
            std::cout << "ERROR: invalid range! try again!" << std::endl;
        }
    }

    std::cout << "Armstrong number(s) between " << lb << "-" << ub << " are:" << std::endl;

    for (int i = lb; i < ub; ++i) {
        if (is_armstrong(i)) {
            std::cout << i << std::endl;
        }
    }

    return 0;
}
