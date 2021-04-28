class Solution {
public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c);
        while (l <= r) {
            long sum = long(l * l) + long(r * r);
            if (sum == c) {
                return true;
            } else if (sum > c) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};