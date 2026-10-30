#include <iostream>
#include <cmath>

double monthly_payment(double P, double r, int n) {
    return P * r * std::pow(1 + r, n) / (std::pow(1 + r, n) - 1);
}

double bisection_method(double P, double M, int n) {
    double a = 1e-9;
    double b = 1.0;
    double c;

    while (b - a > 1e-9) {
        c = (a + b) / 2.0;
        double f_c = P * c * std::pow(1 + c, n) / (std::pow(1 + c, n) - 1) - M;
        if (f_c == 0.0) {
            break;
        }
        else if (f_c * (P * a * std::pow(1 + a, n) / (std::pow(1 + a, n) - 1) - M) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    return (a + b) / 2.0;
}

int main() {
    double value, down_payment, M;
    int n;

    std::cout << "Enter the value of your car: ";
    std::cin >> value;
    std::cout << "Enter your down payment: ";
    std::cin >> down_payment;
    std::cout << "Enter your monthly payment: ";
    std::cin >> M;
    std::cout << "Enter the number of payments: ";
    std::cin >> n;

    double P = value - down_payment;
    double r = bisection_method(P, M, n) * 12 * 100;

    std::cout << "You estimated APR (percentage) is: " << r << std::endl;

    return 0;
}
