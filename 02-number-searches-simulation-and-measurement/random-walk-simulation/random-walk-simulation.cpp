#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int main() {
    int n, T;
    std::cout << "Enter the steps of 2D random walk: ";
    std::cin >> n;
    std::cout << "Enter the number of trials: ";
    std::cin >> T;

    std::srand(std::time(0)); // Seed for random number generation

    double total_distance = 0;

    for (int t = 0; t < T; ++t) {
        int x = 0, y = 0;
        for (int step = 0; step < n; ++step) {
            int direction = std::rand() % 4;
            switch (direction) {
            case 0: y += 1; break; // Move up
            case 1: y -= 1; break; // Move down
            case 2: x -= 1; break; // Move left
            case 3: x += 1; break; // Move right
            }
        }
        total_distance += std::sqrt(x * x + y * y);
    }

    double expected_distance = total_distance / T;
    std::cout << "Expected distance: " << expected_distance << std::endl;
    std::cout << "Theoretical distance: " << std::sqrt(n) << std::endl;

    return 0;

}