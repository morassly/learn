class Solution {
    const int mod = 1e9 + 7;

public:
    int rearrangeSticks(int n, int k) {
        vector<int> f(k + 1);
        f[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = min(k, i); j > 0; --j) {
                f[j] = ((long long)f[j] * (i - 1) % mod + f[j - 1]) % mod;
            }
            f[0] = 0;
        }
        return f[k];
    }
};