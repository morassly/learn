class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (auto coin : coins) {
            for (int j = coin; j <= amount; ++j)
                dp[j] += dp[j - coin];
        }
        return dp[amount];
    }
};