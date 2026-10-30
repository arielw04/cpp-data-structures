#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

const int MAXWORDS = 1000; // Maximum unique words

// Define the WordEntry structure
struct WordEntry {
    string word;   // Word itself
    int frequency; // Frequency count
};

// Function to normalize a word (convert to lowercase and remove punctuation)
string normalizeWord(const string& word) {
    string normalized;
    for (char ch : word) {
        if (isalpha(ch)) {          // Keep only alphabetic characters
            normalized += tolower(ch); // Convert to lowercase
        }
    }
    return normalized;
}

// Function to find a word in the array; returns its index or -1 if not found
int findWord(const WordEntry words[], int size, const string& word) {
    for (int i = 0; i < size; ++i) {
        if (words[i].word == word) {
            return i;
        }
    }
    return -1;
}

int main() {
    WordEntry words[MAXWORDS]; // Array to store unique words and their frequencies
    int wordCount = 0;         // Current count of unique words

    string inputFilename, outputFilename;

    // Prompt the user for the input filename
    cout << "Enter the input filename: ";
    cin >> inputFilename;

    ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << inputFilename << endl;
        return 1;
    }

    string word;
    while (inputFile >> word) {
        // Normalize the word
        string normalized = normalizeWord(word);

        if (normalized.empty()) {
            continue; // Skip empty normalized words
        }

        // Check if the word is already in the array
        int index = findWord(words, wordCount, normalized);
        if (index != -1) {
            // Word exists, increment its frequency
            words[index].frequency++;
        }
        else {
            // Word not found, add it to the array
            if (wordCount < MAXWORDS) {
                words[wordCount].word = normalized;
                words[wordCount].frequency = 1;
                wordCount++;
            }
            else {
                cerr << "Maximum unique word limit (" << MAXWORDS << ") reached. Stopping further processing." << endl;
                break;
            }
        }
    }

    inputFile.close();

    // Prompt the user for the output filename
    cout << "Enter the output filename: ";
    cin >> outputFilename;

    ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        cerr << "Error: Could not open file " << outputFilename << endl;
        return 1;
    }

    // Write each unique word and its frequency to the output file
    for (int i = 0; i < wordCount; ++i) {
        outputFile << words[i].word << ": " << words[i].frequency << endl;
    }

    outputFile.close();

    cout << "Word frequencies have been written to " << outputFilename << endl;

    return 0;
}
