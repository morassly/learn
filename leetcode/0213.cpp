class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        auto f1 = 0, f2 = 0, s1 = nums[0], s2 = nums[1];
        for (int i = 1; i < n - 1; i++) {
            auto t1 = s1, t2 = s2;
            s1 = max(f1 + nums[i], s1);
            s2 = max(f2 + nums[i + 1], s2);
            f1 = t1;
            f2 = t2;
        }
        return max(s1, s2);
    }
};