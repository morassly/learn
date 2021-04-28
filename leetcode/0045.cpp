class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for (int last = 0, mx = 0, cur = 0; cur < n - 1; cur++) {
            mx = max(mx, nums[cur] + cur);
            if (cur == last) {
                last = mx;
                count++;
            }
        }
        return count;
    }
};