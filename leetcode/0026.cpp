class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        int i = 0;
        for (auto j = 0; j < n; j++) {
            if (nums[i] != nums[j]) {
                nums[++i] = nums[j];
            }
        }
        return n == 0 ? 0 : i + 1;
    }
};