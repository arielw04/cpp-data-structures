#include <iostream>
#include <cmath>

static bool is_prime(int n) {
	if (n <= 1) return false;
	for (int i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
int main() {
    int lb, ub;
    while (true) {
        std::cout << "Enter left bound of the range (lb): ";
        std::cin >> lb;
        std::cout << "Enter right bound of the range (ub): ";
        std::cin >> ub;
        if (lb > 0 && lb < ub) {
  
            break;
        }
        else {
            std::cout << "ERROR: invalid range! try again!" << std::endl;
        }
    }
    int prime_count = 0;
    std::cout << "Prime number(s) between " << lb << "-" << ub << " are:" << std::endl;

    for (int i = lb; i < ub; ++i) {
        if (is_prime(i)) {
            std::cout << i << std::endl;
            ++prime_count;
        }
    }
    std::cout << "There are total of " << prime_count << " prime numbers in the range." << std::endl;

    return 0;
}