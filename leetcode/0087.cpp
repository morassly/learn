class Solution {
public:
    bool isScramble(string s1, string s2) {
        int dp[31][31][31];
        memset(dp, 0, sizeof dp);
        auto issamechar = [&](int i, int j, int length) {
            int chars[26]{0};
            for (int k = 0; k < length; k++) {
                chars[s1[i + k] - 'a']++;
                chars[s2[j + k] - 'a']--;
            }
            return !any_of(chars, chars + 26, [](const auto& entry) { return entry != 0; });
        };
        auto dfs = [&](auto&& dfs, int i, int j, int length) -> bool {
            if (dp[i][j][length]) return dp[i][j][length] == 1;
            if (s1.substr(i, length) == s2.substr(j, length)) {
                dp[i][j][length] = 1;
                return true;
            }
            if (!issamechar(i, j, length)) {
                dp[i][j][length] = -1;
                return false;
            }

            for (int k = 1; k < length; ++k) {
                if (dfs(dfs, i, j, k) && dfs(dfs, i + k, j + k, length - k)) {
                    dp[i][j][length] = 1;
                    return true;
                }
                // 交换的情况
                if (dfs(dfs, i, j + length - k, k) &&
                    dfs(dfs, i + k, j, length - k)) {
                    dp[i][j][length] = 1;
                    return true;
                }
            }

            dp[i][j][length] = -1;
            return false;
        };
        return dfs(dfs, 0, 0, s1.size());
    }
};