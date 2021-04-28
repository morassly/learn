class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> queens(n, string(n, '.'));
        auto dfs = [&](auto&& dfs, int row, int col, int l, int r) {
            if (row == n) {
                ans.push_back(queens);
                return;
            }
            for (auto cur = ((1 << n) - 1) & (~(col | l | r)); cur;
                 cur &= (cur - 1)) {
                int pos = cur & (-cur);
                int j = __builtin_ctz(pos);
                queens[row][j] = 'Q';
                dfs(dfs, row + 1, col | pos, (l | pos) << 1, (r | pos) >> 1);
                queens[row][j] = '.';
            }
        };
        dfs(dfs, 0, 0, 0, 0);
        return ans;
    }
};