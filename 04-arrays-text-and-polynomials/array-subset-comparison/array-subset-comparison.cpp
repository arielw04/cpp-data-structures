#include <iostream>

bool isSubset(int arrA[], int sizeA, int arrB[], int sizeB) {
    for (int i = 0; i < sizeA; ++i) {
        bool found = false;
        for (int j = 0; j < sizeB; ++j) {
            if (arrA[i] == arrB[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

int main() {
    int sizeA, sizeB;

    // Ask the user for the size of array A
    std::cout << "Enter size of arr A: ";
    std::cin >> sizeA;
    int* arrA = new int[sizeA];

    // Ask the user to enter the elements of array A
    std::cout << "Enter arr A of size " << sizeA << ": ";
    for (int i = 0; i < sizeA; ++i) {
        std::cin >> arrA[i];
    }

    // Ask the user for the size of array B
    std::cout << "Enter size of arr B: ";
    std::cin >> sizeB;
    int* arrB = new int[sizeB];

    // Ask the user to enter the elements of array B
    std::cout << "Enter arr B of size " << sizeB << ": ";
    for (int i = 0; i < sizeB; ++i) {
        std::cin >> arrB[i];
    }

    // Check subsets
    bool aIsSubsetOfB = isSubset(arrA, sizeA, arrB, sizeB);
   
    bool bIsSubsetOfA = isSubset(arrB, sizeB, arrA, sizeA);

    // Determine and display the result
    if (aIsSubsetOfB && bIsSubsetOfA) {
        std::cout << "A is equal to B." << std::endl;
    }
    else if (aIsSubsetOfB) {
        std::cout << "A is a subset of B." << std::endl;
    }
    else if (bIsSubsetOfA) {
        std::cout << "B is a subset of A." << std::endl;
    }
    else {
        std::cout << "Neither is a subset of the other." << std::endl;
    }

    
    delete[] arrA;
    delete[] arrB;

    return 0;
}
