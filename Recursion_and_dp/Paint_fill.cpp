#include <bits/stdc++.h>
using namespace std;

// TC = O(M * N)
// SC = O(M * N)

class Solution
{
public:

    int m, n;
    int originalColor;

    void dfs(int sr, int sc, vector<vector<int>>& image, int newColor) {
        if (sr < 0 || sc < 0 || sr >= m || sc >= n || image[sr][sc] != originalColor) {
            return;
        }
        image[sr][sc] = newColor;
        dfs(sr + 1, sc, image, newColor);
        dfs(sr - 1, sc, image, newColor);
        dfs(sr, sc + 1, image, newColor);
        dfs(sr, sc - 1, image, newColor);
    }

    vector<vector<int>> paintFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        originalColor = image[sr][sc];
        if (originalColor != newColor) {
            dfs(sr, sc, image, newColor);
        }
        return image;
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 1, 0},
        {1, 0, 1}
    };
    vector<vector<int>> ans = solution.paintFill(image, 1, 1, 2);

    for(auto num : ans)
    {
       for(auto it : num)
       {
            cout << it << " ";
       }
       cout << endl;
    }

    cout << endl;

    return 0;
}
