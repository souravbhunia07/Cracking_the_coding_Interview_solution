// Method - 1
#include <bits/stdc++.h>
using namespace std;

string checkPermutation(string w1, string w2)
{
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());
    if(w1 == w2)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}

int main()
{
    string word1, word2;
    cin >> word1 >> word2;
    checkPermutation(word1, word2);
    return 0;
}

// Method - 2 (Check if the two strings have identical character counts.)
#include <iostream>
#include <cstring>

// Function to check if two strings are permutations of each other
bool isPermutation(const std::string& str1, const std::string& str2) {
    // If the lengths of the strings are different, they cannot be permutations
    if (str1.length() != str2.length()) {
        return false;
    }

    // Initialize an array to store the count of characters (assuming ASCII characters)
    const int ASCII_SIZE = 128; // ASCII has 128 characters
    int charCount[ASCII_SIZE] = {0};

    // Count characters in the first string
    for (char ch : str1) {
        charCount[static_cast<int>(ch)]++;
    }

    // Subtract character counts from the second string
    for (char ch : str2) {
        charCount[static_cast<int>(ch)]--;
        // If any character count becomes negative, it means the strings are not permutations
        if (charCount[static_cast<int>(ch)] < 0) {
            return false;
        }
    }

    // If all character counts are zero, the strings are permutations
    return true;
}

int main() {
    std::string str1, str2;

    std::cout << "Enter the first string: ";
    std::cin >> str1;

    std::cout << "Enter the second string: ";
    std::cin >> str2;

    if (isPermutation(str1, str2)) {
        std::cout << "The strings are permutations of each other." << std::endl;
    } else {
        std::cout << "The strings are not permutations of each other." << std::endl;
    }

    return 0;
}
