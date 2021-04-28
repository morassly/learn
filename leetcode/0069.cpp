class Solution {
public:
    int mySqrt(int x) {
        if (x < 0) return -1;
        long l = 0, r = (long)x + 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            long temp = (long)mid * (long)mid;
            if (temp <= x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l - 1;
    }
};