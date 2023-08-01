#include <iostream>
#include <string>
using namespace std;

bool isSubstring(const string& str, const string& substr) {
    return str.find(substr) != string::npos;
}

bool isRotation(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return false; // Strings of different lengths cannot be rotations of each other
    }

    string concatenated = s1 + s1;
    return isSubstring(concatenated, s2);
}

int main() {
    string s1 = "waterbottle";
    string s2 = "erbottlewat";

    if (isRotation(s1, s2)) {
        cout << s2 << " is a rotation of " << s1 << endl;
    } else {
        cout << s2 << " is not a rotation of " << s1 << endl;
    }

    return 0;
}
