#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void generateParens(int c1, int c2, vector<string> &ans, string v, int n)
    {
        if(c1 == n && c2 == n)
        {
            ans.push_back(v);
            return;
        }
        if(c1 < n)
        {
            generateParens(c1 + 1, c2, ans, v + "(", n);
        }
        if(c2 < c1)
        {
            generateParens(c1, c2 + 1, ans, v + ")", n);
        }
    }

    vector<string> parens(int n)
    {
        vector<string> ans;
        string v = "";
        generateParens(0, 0, ans, v, n);
        return ans;
    }
};

int main()
{
    Solution solution;
    int n = 3;
    vector<string> ans = solution.parens(n);

    for(auto str : ans)
    {
        cout << str << " ";
    }

    cout << endl;

    return 0;
}
