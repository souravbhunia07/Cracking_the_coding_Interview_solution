// O(N)

#include <iostream>
#include <string>
using namespace std;

string compressString(const string& s) {
    if (s.empty()) {
        return s;
    }

    string compressed;
    int count = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            count++;
        } else {
            compressed.push_back(s[i - 1]);
            compressed += to_string(count);
            count = 1;
        }
    }

    // Add the last character and its count to the compressed string
    compressed.push_back(s.back());
    compressed += to_string(count);

    // Check if the compressed string is shorter than the original string
    if (compressed.length() < s.length()) {
        return compressed;
    } else {
        return s;
    }
}

int main() {
    cout << compressString("aabcccccaaa") << endl;  // Output: "a2b1c5a3"
    cout << compressString("abcd") << endl;         // Output: "abcd" (compressed string is longer)
    return 0;
}
