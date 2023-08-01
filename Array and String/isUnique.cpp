// With data Structure
#include <bits/stdc++.h>
using namespace std;

bool isUnique(string s)
{
    unordered_map<char, int>mp;
    bool flag = true;
    for(int i = 0; i < s.size(); i++)
    {
        mp[s[i]]++;
    }
    for(auto it : mp)
    {
        if(it.second != 1)
        {
            flag = false;
            break;
        }
    }
    flag == true ? cout << "True" : cout << "False";
}

int main()
{
    string s;
    cin >> s;
    isUnique(s);
    return 0;
}

// Another method using set
#include <iostream>
#include <unordered_set>

bool has_unique_characters_with_ds(const std::string& input_string) {
    std::unordered_set<char> char_set;
    for (char ch : input_string) {
        if (char_set.find(ch) != char_set.end()) {
            return false;
        }
        char_set.insert(ch);
    }
    return true;
}

int main() {
    std::string input_string;
    std::cout << "Enter a string: ";
    std::cin >> input_string;

    bool result = has_unique_characters_with_ds(input_string);
    if (result) {
        std::cout << "The string has all unique characters.\n";
    } else {
        std::cout << "The string does not have all unique characters.\n";
    }

    return 0;
}


// Without Data Strcuture
#include <iostream>

bool has_unique_characters_without_ds(const std::string& input_string) {
    int length = input_string.length();
    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            if (input_string[i] == input_string[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::string input_string;
    std::cout << "Enter a string: ";
    std::cin >> input_string;

    bool result = has_unique_characters_without_ds(input_string);
    if (result) {
        std::cout << "The string has all unique characters.\n";
    } else {
        std::cout << "The string does not have all unique characters.\n";
    }

    return 0;
}
