class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        static auto _ = []() {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return 0;
        }();
        auto countoneanszero = [](auto&& s) {
            int a = 0, b = 0;
            for (auto&& c : s)
                if (c == '0')
                    a++;
                else
                    b++;
            return make_tuple(a, b);
        };
        for (auto&& str : strs) {
            auto&& [a, b] = countoneanszero(str);
            for (int i = m; i >= a; --i) {
                for (int j = n; j >= b; --j) {
                    dp[i][j] = max(dp[i][j], dp[i - a][j - b] + 1);
                }
            }
        }
        return dp[m][n];
    }
};