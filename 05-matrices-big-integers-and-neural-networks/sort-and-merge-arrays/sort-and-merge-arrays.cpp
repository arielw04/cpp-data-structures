#include <iostream>
using namespace std;

void mergeArrays(int* arr1, int size1, int* arr2, int size2, int* mergedArray) {
    int i = 0, j = 0, k = 0;

    // Merge the two arrays into mergedArray in ascending order
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArray[k++] = arr1[i++];
        }
        else {
            mergedArray[k++] = arr2[j++];
        }
    }

    // Copy the remaining elements of arr1, if any
    while (i < size1) {
        mergedArray[k++] = arr1[i++];
    }

    // Copy the remaining elements of arr2, if any
    while (j < size2) {
        mergedArray[k++] = arr2[j++];
    }
}

int main() {
    int size1, size2;

    cout << "Enter the number of elements in the first array: ";
    cin >> size1;
    int* arr1 = new int[size1];

    cout << "Enter elements in the first array:\n";
    for (int i = 0; i < size1; ++i) {
        cin >> arr1[i];
    }

    cout << "Enter the number of elements in the second array: ";
    cin >> size2;
    int* arr2 = new int[size2];

    cout << "Enter elements in the second array:\n";
    for (int i = 0; i < size2; ++i) {
        cin >> arr2[i];
    }

    // Sort the individual arrays (using bubble sort for simplicity)
    for (int i = 0; i < size1 - 1; ++i) {
        for (int j = 0; j < size1 - i - 1; ++j) {
            if (arr1[j] > arr1[j + 1]) {
                int temp = arr1[j];
                arr1[j] = arr1[j + 1];
                arr1[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size2 - 1; ++i) {
        for (int j = 0; j < size2 - i - 1; ++j) {
            if (arr2[j] > arr2[j + 1]) {
                int temp = arr2[j];
                arr2[j] = arr2[j + 1];
                arr2[j + 1] = temp;
            }
        }
    }

    int* mergedArray = new int[size1 + size2];
    mergeArrays(arr1, size1, arr2, size2, mergedArray);

    cout << "Merged array: ";
    for (int i = 0; i < size1 + size2; ++i) {
        cout << mergedArray[i] << " ";
    }
    cout << endl;

    // Free allocated memory
    delete[] arr1;
    delete[] arr2;
    delete[] mergedArray;

    return 0;
}
