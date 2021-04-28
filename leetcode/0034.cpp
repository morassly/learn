class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int low = binary(nums, target, false);
        int up = binary(nums, target, true);
        if (low == up) {
            return vector<int>{-1, -1};
        }
        return vector<int>{low, up - 1};
    }

    int binary(vector<int> &a, int x, bool flag) {
        int l = 0, r = a.size();
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] <= x) {
                if (!flag && a[mid] == x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                r = mid;
            }
        }
        return l;
    }
};