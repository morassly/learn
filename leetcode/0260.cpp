class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int tmp = 0;
        for (auto& num : nums) tmp ^= num;
        tmp &= -tmp;
        auto ans = vector<int>{0, 0};
        for (auto& num : nums)
            if (tmp & num)
                ans[0] ^= num;
            else
                ans[1] ^= num;
        return ans;
    }
};