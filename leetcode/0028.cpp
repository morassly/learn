class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (n == 0) return 0;
        vector<int> next(n + 1, 0);
        auto getnet = [&]() {
            int i = 0, k = -1;
            next[i] = k;
            while (i < n) {
                while (k != -1 && needle[i] != needle[k]) {
                    k = next[k];
                }
                next[++i] = ++k;
                if (needle[k] == needle[i]) next[i] = next[k];
            }
        };
        getnet();
        int i = 0, j = 0;
        for (; i < m && j < n;) {
            if (j == -1 || haystack[i] == needle[j]) {
                j++;
                i++;
            } else {
                j = next[j];
            }
        }
        if (j == n) {
            return i - j;
        } else {
            return -1;
        }
    }
};