class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(),n = text2.size();
        int dp[2][n+1];
        fill(dp[0],dp[0]+n+1,0);
        fill(dp[1],dp[1]+n+1,0);
        for (int i = 0; i < m;i++){
            for (int j = 0; j < n;j++){
                if (text1[i] == text2[j]) {
                    dp[(i+1)&1][j+1] = dp[i&1][j] + 1;
                } else {
                    dp[(i+1)&1][j+1] = max(dp[(i+1)&1][j],dp[i&1][j+1]);
                }
            }
        }
        return dp[m&1][n];
    }
};