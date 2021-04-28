class Solution {
public:
    int m[256];
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int ans = 0;
        for (int i = 0, j = 0; i < len; ++i) {
            int k = m[s[i]];
            if (k != 0) {
                j = max(j, k);
            }
            ans = max(ans, i - j + 1);
            m[s[i]] = i + 1;
        }
        return ans;
    }
};