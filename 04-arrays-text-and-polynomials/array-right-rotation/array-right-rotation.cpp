#include <iostream>

// Function to rotate the array to the right
void rotateArray(int arr[], int n, int k) {
    k = k % n;

    
    int* temp = new int[n];

    for (int i = 0; i < k; ++i) {
        temp[i] = arr[n - k + i];
    }

    for (int i = k; i < n; ++i) {
        temp[i] = arr[i - k];
    }

    for (int i = 0; i < n; ++i) {
        arr[i] = temp[i];
    }

    // Free the temporary array
    delete[] temp;
}

int main() {
    int n, k;

    // Ask the user for the length of the array
    std::cout << "Enter the size of your input: ";
    std::cin >> n;

    // allocate the array
    int* arr = new int[n];

    // Ask the user to enter the array elements
    std::cout << "Enter arr of size " << n << ": ";
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    // Ask the user for the number of rotations
    std::cout << "Position k = ";
    std::cin >> k;

    // Rotate the array
    rotateArray(arr, n, k);

    // Print the rotated array
    std::cout << "Rotated " << k << " times: ";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Free allocated memory
    delete[] arr;

    return 0;
}
