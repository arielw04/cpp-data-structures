#include <iostream>

void sortArray(int arr[], int size) {
    // Simple bubble sort to sort the array
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    // Ask the user for the length of the array
    std::cout << "Enter the size of your input: ";
    std::cin >> n;

    
    int* arr = new int[n];

    // Ask the user to enter the array elements
    std::cout << "Enter arr of size " << n << ": ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Sort the array
    sortArray(arr, n);

    // Find and print the median
    double median;
    if (n % 2 == 0) {
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
    }
    else {
        median = arr[n / 2];
    }
    std::cout << "Median of the input array is " << median << std::endl;

    // Free dynamically allocated memory
    delete[] arr;

    return 0;
}
