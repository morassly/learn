class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        static auto _ = []() {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return 0;
        }();
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m, '.'));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0, next = j;
                while (next < n && box[i][next] != '*') {
                    cnt += (box[i][next] == '#');
                    ++next;
                }

                if (next < n) ans[next][m - i - 1] = '*';
                for (int s = 1; s <= cnt; ++s) {
                    ans[next - s][m - i - 1] = '#';
                }
                j = next;
            }
        }
        return ans;
    }
};
