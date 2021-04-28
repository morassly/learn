class Solution {
public:
    int dp[1001][1001];
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        for (auto i = n - 1; i >= 0; i--) {
            dp[i][i] = 1;
            for (auto j = i + 1; j < n; j++) {
                if (s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
        return dp[0][n - 1];
    }
};