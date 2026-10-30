#include <iostream>
#include <cstring>

void reverseWords(char* sentence) {
    int length = std::strlen(sentence);
    int start = 0;

    // Reverse entire sentence first
    for (int i = 0; i < length / 2; ++i) {
        char temp = sentence[i];
        sentence[i] = sentence[length - i - 1];
        sentence[length - i - 1] = temp;
    }

    // Reverse each word in the reversed sentence
    for (int end = 0; end <= length; ++end) {
        if (sentence[end] == ' ' || sentence[end] == '\0') {
            for (int i = start, j = end - 1; i < j; ++i, --j) {
                char temp = sentence[i];
                sentence[i] = sentence[j];
                sentence[j] = temp;
            }
            start = end + 1;
        }
    }
}

int main() {
    char sentence[1000];

    // Ask the user to enter a sentence
    std::cout << "Enter a sentence: ";
    std::cin.getline(sentence, 1000);

    // Reverse the words in the sentence
    reverseWords(sentence);

    // Print the reversed sentence
    std::cout << "Reversed words sentence: " << sentence << std::endl;

    return 0;
}
