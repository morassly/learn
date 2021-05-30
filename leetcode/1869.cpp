class Solution {
public:
    bool checkZeroOnes(string s) {
        int len1 = 0, len0 = 0;
        int max1 = 0, max0 = 0;
        for (auto& each : s) {
            if (each == '0') {
                ++len0;
                max0 = max(max0, len0);
                len1 = 0;
            } else {
                ++len1;
                max1 = max(max1, len1);
                len0 = 0;
            }
        }
        return max1 > max0;
    }
};