class Solution {
public:
    int totalNQueens(int n) {
        auto ans = 0;
        auto dfs = [&](auto&& dfs, int row, int col, int l, int r) {
            if (row == n) {
                ans++;
                return;
            }
            for (auto cur = ((1 << n) - 1) & (~(col | l | r)); cur;
                 cur &= (cur - 1)) {
                int pos = cur & (-cur);
                dfs(dfs, row + 1, col | pos, (l | pos) << 1, (r | pos) >> 1);
            }
        };
        dfs(dfs, 0, 0, 0, 0);
        return ans;
    }
};