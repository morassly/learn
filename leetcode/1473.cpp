const int INF = 0x3f3f3f3f;  //INF + INF 不会爆int
int f[105][25][105];

class Solution {
    static constexpr int INF = 0x3f3f3f3f;

public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(target + 1, INF)));

        for (int i = 1; i <= m; i++) {
            int color = houses[i - 1];
            for (int j = 1; j <= n; j++) {
                if (color != 0 && color != j) continue;
                for (int k = 1; k <= target; k++) {
                    if (k > i) continue;
                    for (int p = 1; p <= n; p++) {
                        if (p != j) {  //颜色不同
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][p][k - 1]);
                        } else {
                            if (i == 1 && k == 1) dp[i][j][k] = 0;
                            dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                        }
                    }
                    if (dp[i][j][k] != INF && color == 0) {
                        dp[i][j][k] += cost[i - 1][j - 1];
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[m][i][target]);
        }
        return ans == INF ? -1 : ans;
    }
};

class Solution1 {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(f, -1, sizeof f);

        auto dfs = [&](auto&& dfs, int hidx, int precol, int cnt, int sum) -> int {
            if (cnt > target) return INF;
            if (hidx == m) return cnt == target ? 0 : INF;
            if (f[hidx][precol][cnt] != -1) return f[hidx][precol][cnt];

            int col = houses[hidx], ans = INF;
            if (col) {
                auto ncnt = precol == col ? cnt : cnt + 1;
                auto cur = dfs(dfs, hidx + 1, col, ncnt, sum);
                ans = min(ans, cur);
            } else {
                for (int i = 1; i <= n; i++) {
                    auto ncnt = precol == i ? cnt : cnt + 1;
                    auto cur = dfs(dfs, hidx + 1, i, ncnt, sum + cost[hidx][i - 1]);
                    ans = min(ans, cur + cost[hidx][i - 1]);
                }
            }
            return f[hidx][precol][cnt] = ans;
        };
        auto ans = dfs(dfs, 0, 0, 0, 0);
        return ans == INF ? -1 : ans;
    }
};