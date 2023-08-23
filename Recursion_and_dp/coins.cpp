#include <bits/stdc++.h>
using namespace std;

// So, the time complexity is O(n * sum), and the space complexity is also O(n * sum).

class Solution
{
public:
    
    int coinsSum(int sum, vector<int> &coins)
    {
        int n = coins.size();
        int t[n + 1][sum + 1];

        // Base Case
        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j < sum + 1; j++)
            {
                if(i == 0)
                {
                    t[i][j] = 0;
                }
                if(j == 0)
                {
                    t[i][j] = 1;
                }
            }
        }

        // Choice Diagram
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < sum + 1; j++)
            {
                if(coins[i - 1] <= j)
                {
                    t[i][j] = t[i - 1][j] + t[i][j - coins[i - 1]];
                }
                else
                {
                    t[i][j] = t[i - 1][j];
                }
            }
        }

        return t[n][sum];
    }
};

int main()
{
    Solution solution;
    vector<int> coins = {1, 2, 5};
    int ans = solution.coinsSum(5, coins);

    cout << ans << endl;

    return 0;
}
