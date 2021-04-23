class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,1);
        sort(nums.begin(),nums.end());
        int maxlen = 0,maxval = 0;
        for(int i = 0; i < n;i++){
            for (int j = 0; j < i;j++){
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > maxlen){
                maxlen = dp[i];
                maxval = nums[i];
            }
        }
        vector<int> ans;
        if (maxlen == 1){
            ans.push_back(nums[0]);
            return ans;
        }
        for (int i = n - 1 ;maxlen > 0 ; i--){
            if (maxval % nums[i] == 0 && dp[i] == maxlen){
                maxlen--;
                maxval = nums[i];
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};