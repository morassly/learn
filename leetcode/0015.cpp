class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] > 0) return res;
            if (i == 0 || nums[i] != nums[i - 1]) {
                int l = i + 1, r = nums.size() - 1;
                while (l < r) {
                    if (nums[i] + nums[l] + nums[r] < 0)
                        l++;
                    else if (nums[i] + nums[l] + nums[r] > 0)
                        r--;
                    else {
                        vector<int> temp = {nums[i], nums[l], nums[r]};
                        res.push_back(temp);
                        while (l < r && nums[l] == nums[l + 1]) l++;
                        while (l < r && nums[r] == nums[r - 1]) r--;
                        l++, r--;
                    }
                }
            }
        }
        return res;
    }
};