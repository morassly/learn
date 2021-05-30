class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        auto dfs = [&](auto&& dfs, auto ans, auto ind) {
            if (ind == n) {
                sum += ans;
                return;
            }
            dfs(dfs, ans ^ nums[ind], ind + 1);
            dfs(dfs, ans, ind + 1);
        };
        dfs(dfs, 0, 0);
        return sum;
    }
};
class Solution1 {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        auto dfs = [&](auto&& dfs, auto ans, auto ind) {
            sum += ans;
            if (ind == n)
                return;
            for (auto j = ind; j < n; ++j) {
                dfs(dfs, ans ^ nums[j], j + 1);
            }
        };
        dfs(dfs, 0, 0);
        return sum;
    }
};
class Solution2 {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (auto& each : nums)
            sum |= each;
        return sum << (n - 1);
    }
};