class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0) return -1;
        auto low = nums.begin(), high = nums.end() - 1;
        while (low < high) {
            auto mid = low + (high - low) / 2;
            if (*mid >= *low) {
                if (*low <= target && target <= *mid)
                    high = mid;
                else
                    low = mid + 1;
            } else {
                if (*high >= target && target > *mid)
                    low = mid + 1;
                else
                    high = mid;
            }
        }
        if (*low == target) return low - nums.begin();
        return -1;
    }
};