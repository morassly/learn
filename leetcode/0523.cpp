class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int pre = 0, n = nums.size();
        mp[0] = -1;
        for (int i = 0; i < n; ++i) {
            pre = (pre + nums[i]) % k;
            if (mp.count(pre)) {
                if (i - mp[pre] >= 2)
                    return true;
            } else
                mp[pre] = i;
        }
        return false;
    }
};