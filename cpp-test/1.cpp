#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;
vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> sum1(m + 1, vector<int>(n + 2));
    vector<vector<int>> sum2(m + 1, vector<int>(n + 2));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            sum1[i][j] = sum1[i - 1][j - 1] + grid[i - 1][j - 1];
            sum2[i][j] = sum2[i - 1][j + 1] + grid[i - 1][j - 1];
        }
    }
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << sum2[i][j] << ' ';
        }
        cout << endl;
    }
    set<int,std::greater<int>> temp;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            temp.emplace(grid[i][j]);
            for (int k = i + 2; k < m; k += 2) {
                int ux = i, uy = j;
                int dx = k, dy = j;
                int lx = (i + k) / 2, ly = j - (k - i) / 2;
                int rx = (i + k) / 2, ry = j + (k - i) / 2;
                if (ly < 0 || ry >= n) {
                    break;
                }
                temp.emplace(
                    (sum2[lx + 1][ly + 1] - sum2[ux][uy + 2]) +
                    (sum1[rx + 1][ry + 1] - sum1[ux][uy]) +
                    (sum1[dx + 1][dy + 1] - sum1[lx][ly]) +
                    (sum2[dx + 1][dy + 1] - sum2[rx][ry + 2]) -
                    (grid[ux][uy] + grid[dx][dy] + grid[lx][ly] + grid[rx][ry]));
            }
        }
    }
    int cnt = min(3, (int)temp.size());
    int i = 0;
    vector<int> ret;
    for (auto iter = temp.begin(); i < cnt; ++i, ++iter) {
        ret.emplace_back(*iter);
    }
    return ret;
}

int main() {
    vector<vector<int>> grid{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    for (auto ret : getBiggestThree(grid)) {
        cout << ret << ' ';
    }
    cout << endl;
    return 0;
}