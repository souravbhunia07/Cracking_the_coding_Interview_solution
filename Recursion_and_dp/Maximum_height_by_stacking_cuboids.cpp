#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto& c : cuboids) {
            sort(c.begin(), c.end()); // Sort dimensions in non-decreasing order
        }
        
        sort(cuboids.begin(), cuboids.end()); // Sort cuboids in non-decreasing order of dimensions
        
        int n = cuboids.size();
        vector<int> dp(n, 0); // dp[i] stores the maximum height achievable with cuboid i at the bottom
        
        for (int curr = 0; curr < n; ++curr) {
            dp[curr] = cuboids[curr][2]; // Initialize with the height of the current cuboid
            
            for (int prev = 0; prev < curr; ++prev) {
                if (cuboids[curr][0] >= cuboids[prev][0] && cuboids[curr][1] >= cuboids[prev][1] && cuboids[curr][2] >= cuboids[prev][2]) {
                    dp[curr] = max(dp[curr], dp[prev] + cuboids[curr][2]); // Update with maximum height
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution solution;
    
    vector<vector<int>> cuboids = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    int maxHeight = solution.maxHeight(cuboids);
    
    cout << "Maximum height achievable: " << maxHeight << endl;
    
    return 0;
}
