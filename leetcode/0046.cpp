class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        auto dfs = [&](auto&& dfs, auto i) {
            if (i == n) {
                ans.emplace_back(nums);
                return;
            }
            for (auto j = i; j < n; j++) {
                swap(nums[i], nums[j]);
                dfs(dfs, i + 1);
                swap(nums[i], nums[j]);
            }
        };
        dfs(dfs, 0);
        return ans;
    }
};