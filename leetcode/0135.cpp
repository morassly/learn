class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> dp(n,1);
        for (auto i = 1; i < n;i++)
            if (ratings[i]>ratings[i-1])
                dp[i]=dp[i-1]+1;
        int ans = 0;
        for (auto i = n-1; i >=0;i--){
            if(i<n-1 && ratings[i] > ratings[i+1]&& dp[i]<=dp[i+1])
                dp[i]=dp[i+1]+1;
            ans += dp[i];
        }
        return ans;
    }
};