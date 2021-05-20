class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        for (auto l = 0, r = n - 1; l < r;) {
            auto i = l, j = r + 1;
            for (;;) {
                for (++i; i < r && nums[i] < nums[l]; i++)
                    ;
                for (--j; j > l && nums[j] > nums[l]; j--)
                    ;
                if (i >= j)
                    break;
                swap(nums[i], nums[j]);
            }
            swap(nums[j], nums[l]);
            if (j == (n - k))
                break;
            else if (j > (n - k))
                r = j - 1;
            else
                l = j + 1;
        }
        return nums[n - k];
    }
};