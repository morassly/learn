class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int presum = 0, n = nums.size(), ans = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i])
                presum++;
            else
                presum--;
            if (mp.find(presum) != mp.end()) {
                ans = max(ans, i - mp[presum]);
            } else {
                mp[presum] = i;
            }
        }
        return ans;
    }
};