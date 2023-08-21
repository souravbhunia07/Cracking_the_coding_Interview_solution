#include <iostream>
#include <vector>
#include <cstring>  // For memset

using namespace std;

class Solution {
public:
    int m, n;
    int t[1001][1001];

    int solve(int i, int j, vector<vector<int>>& obstacleGrid) {
        if (i >= m || i < 0 || j >= n || j < 0 || obstacleGrid[i][j] == 1) {
            return 0;
        }
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (t[i][j] != -1) {
            return t[i][j];
        }
        int right = solve(i, j + 1, obstacleGrid);
        int down = solve(i + 1, j, obstacleGrid);
        return t[i][j] = right + down;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, obstacleGrid);
    }
};

int main() {
    Solution solution;

    // Example obstacle grid
    vector<vector<int>> obstacleGrid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    int result = solution.uniquePathsWithObstacles(obstacleGrid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
