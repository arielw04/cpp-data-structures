#include <iostream>
#include <cstring>

void multiplyLargeNumbers(const char* num1, const char* num2, char* result) {
    int len1 = std::strlen(num1);
    int len2 = std::strlen(num2);
    int* res = new int[len1 + len2]();

    // Perform the multiplication digit by digit
    for (int i = len1 - 1; i >= 0; --i) {
        for (int j = len2 - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j + 1] = sum % 10;
            res[i + j] += sum / 10;
        }
    }

    // Convert the result array to a string
    int k = 0;
    for (int i = 0; i < len1 + len2; ++i) {
        if (!(k == 0 && res[i] == 0)) {
            result[k++] = res[i] + '0';
        }
    }
    if (k == 0) {
        result[k++] = '0';
    }
    result[k] = '\0';

    delete[] res;
}

int main() {
    char num1[101], num2[101];
    std::cout << "Enter the first large number: ";
    std::cin >> num1;
    std::cout << "Enter the second large number: ";
    std::cin >> num2;

    int len1 = std::strlen(num1);
    int len2 = std::strlen(num2);
    char* result = new char[len1 + len2 + 1];

    multiplyLargeNumbers(num1, num2, result);

    std::cout << "Product: " << result << std::endl;

    delete[] result;
    return 0;
}
