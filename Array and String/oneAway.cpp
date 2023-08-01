#include <bits/stdc++.h>
using namespace std;

int oneAway(string w1, string w2, int w1idx, int w2idx)
{
    if(w1idx == 0)
    {
        return w2idx;
    }
    if(w2idx == 0)
    {
        return w1idx;
    }
    
    if(w1[w1idx - 1] == w2[w2idx - 1])
    {
        return oneAway(w1, w2, w1idx - 1, w2idx - 1);
    }
    else
    {
        int insertOperation = oneAway(w1, w2, w1idx, w2idx - 1);
        int deleteOperation = oneAway(w1, w2, w1idx - 1, w2idx);
        int replaceOperation = oneAway(w1, w2, w1idx - 1, w2idx - 1);

        return  min(insertOperation, min(deleteOperation, replaceOperation)) + 1;
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int count = oneAway(s1, s2, s1.size(), s2.size());
    cout << count << endl;
    if(count <= 1)
    {
        cout << "true";
    }
    else 
    {
        cout << "False";
    }
    return 0;
}
