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
