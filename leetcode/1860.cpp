class Solution {
public:
    vector<int> memLeak(int a, int b) {
        int t = 1;
        for (; t <= max(a, b); t++) {
            if (b <= a) {
                a -= t;
            } else {
                b -= t;
            }
        }
        return {t, a, b};
    }
};