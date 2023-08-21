#include <iostream>
#include <vector>

int countWaysToClimbStairs(int n, std::vector<int>& dp) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (dp[n] > -1) {
        return dp[n];
    } else {
        dp[n] = countWaysToClimbStairs(n - 1, dp) + countWaysToClimbStairs(n - 2, dp) + countWaysToClimbStairs(n - 3, dp);
        return dp[n];
    }
}

int main() {
    int n;
    std::cout << "Enter the number of steps: ";
    std::cin >> n;

    std::vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4; // We can reach 3rd step by y ways:- 1 + 1 + 1, 2 + 1, 1 + 2, 3
    int ways = countWaysToClimbStairs(n, dp);
    std::cout << "Number of possible ways: " << ways << std::endl;

    return 0;
}
