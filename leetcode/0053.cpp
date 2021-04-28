class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = 0, ans = nums[0];
        for (auto& i : nums) {
            mx = max(mx + i, i);
            if (mx > ans) {
                ans = mx;
            }
        }
        return ans;
    }
};