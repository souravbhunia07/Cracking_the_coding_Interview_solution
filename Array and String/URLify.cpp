#include <bits/stdc++.h>
using namespace std;

void URLify(string s)
{
    string temp = "";
    for(auto c : s)
    {
        if(c != ' ')
        {
            temp.push_back(c);
        }
        else
        {
            temp.push_back('%');
            temp.push_back('2');
            temp.push_back('0');
        }
    }
    cout << temp;
}

int main()
{
    string s;
    getline(cin, s);
    URLify(s);
    return 0;
}
