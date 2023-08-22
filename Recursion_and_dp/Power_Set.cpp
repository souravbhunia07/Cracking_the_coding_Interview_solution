#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int idx, vector<vector<int>> &ans, vector<int> &v, vector<int> &nums)
    {
        ans.push_back(v);
        for(int i = idx; i < nums.size(); i++)
        {
            if(i != idx && nums[i] == nums[i - 1]) continue;   // check for duplicate
            
            v.push_back(nums[i]);
            solve(i + 1, ans, v, nums);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(nums.begin(), nums.end());
        solve(0, ans, v, nums);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = solution.subsets(nums);
    
    cout << "Subsets: " << endl;
    for (const vector<int>& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
