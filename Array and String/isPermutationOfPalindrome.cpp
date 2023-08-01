#include <bits/stdc++.h>
using namespace std;

int getCharIdx(char c)
{
    if(c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    else if(c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else
    {
        return -1;
    }
}

void isPermutationOfPallindrome(string s)
{
    int oddCount = 0;
    vector<int> freq(26, 0);
    for(auto c : s)
    {
        int idx = getCharIdx(c);
        if(idx != -1)
        {
            freq[idx]++;
            if(freq[idx] % 2 != 0)
            {
                oddCount++;
            }
            else
            {
                oddCount--;
            }
        }
    }
    oddCount <= 1 ? cout << "True" : cout << "False";
}

int main()
{
    string s;
    getline(cin, s);
    isPermutationOfPallindrome(s);
    return 0;
}
