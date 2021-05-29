class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, presum = 0;
        unordered_map<int, int> cnt;
        for (auto&& num : nums) {
            ++cnt[presum];
            presum += num;
            if (cnt.count(presum - k))
                ans += cnt[presum - k];
        }
        return ans;
    }
};