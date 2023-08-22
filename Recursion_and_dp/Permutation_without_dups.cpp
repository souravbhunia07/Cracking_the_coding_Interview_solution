#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    void permutation(vector<int> &nums, vector<vector<int>> &ans, int idx)
    {
        if(idx == nums.size())
        {
            ans.push_back(nums);
        }
        for(int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);
            permutation(nums, ans, idx + 1);
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permuationWithoutDups(vector<int> &nums)
    {
        vector<vector<int>> ans;
        permutation(nums, ans, 0);
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = solution.permuationWithoutDups(nums);

    for(auto num : ans)
    {
        for(auto it : num)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
