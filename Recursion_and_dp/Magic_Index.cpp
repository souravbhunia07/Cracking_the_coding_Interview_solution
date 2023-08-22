#include <bits/stdc++.h>
using namespace std;

int magicSlow(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        if(v[i] == i)
        {
            return i;
        }
    }
    return -1;
}

int t[1001][1001];

int magicFast(vector<int> &v, int start, int end)
{
    if(start > end)
    {
        return 0;
    }
    int mid = (start + end) / 2;
    if(t[start][end] != -1)
    {
        return t[start][end];
    }
    if(v[mid] == mid)
    {
        return t[start][end] = mid;
    }
    else if(v[mid] > mid)
    {
        return t[start][end] = magicFast(v, start, mid - 1);
    }
    else
    {
        return t[start][end] = magicFast(v, mid + 1, end);
    }
    return -1;
}

int magicFastFollowUp(vector<int> &v, int start, int end)
{
    if(start > end)
    {
        return -1;
    }
    int midIndex = (start + end) / 2;
    int midValue = v[midIndex];
    if(t[start][end] != -1)
    {
        return t[start][end];
    }
    if(midIndex == midValue)
    {
        return t[start][end] = midIndex;
    }
    
    // Search Left
    int leftIndex = min(midIndex - 1, midValue);
    int left = magicFastFollowUp(v, start, leftIndex);
    if(left >= 0)
    {
        return t[start][end] = left;
    }

    // Search Right
    int rightIndex = max(midIndex + 1, midValue);
    int right = magicFastFollowUp(v, rightIndex, end);
    return t[start][end] = right;
}


void printhelper(vector<int> &v)
{
    for(auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    int n;

    memset(t, -1, sizeof(t));

    cout << "Enter number of element: ";
    cin >> n;
    cout << endl;

    std::vector<int> v;

    cout << "Enter elements: " << endl;
    for(int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    printhelper(v);

    // int num = magicSlow(v);
    // int num = magicFast(v, 0, v.size() - 1);
    int num = magicFastFollowUp(v, 0, v.size() - 1);
    cout << num << endl;
    return 0;
}

// Testcase:-
// 6
// 4 2 2 3 7 8
