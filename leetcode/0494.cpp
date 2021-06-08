class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        auto diff = sum - target;
        if (diff < 0 || diff % 2) {
            return 0;
        }
        diff /= 2;
        //vector<int> dp(diff+1,0);
        int dp[diff + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (auto& num : nums) {
            for (int j = diff; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        return dp[diff];
    }
};