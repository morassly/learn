/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        vector<bool> visited(10000, false);
        //记录死亡数字
        for (int i = 0; i < deadends.size(); i++) {
            int tmp = stoi(deadends[i]);
            visited[tmp] = true;
        }
        int e = stoi(target);
        if (visited[e]||visited[0]) return -1;
        if (target == "0000") return 0;
        queue<pair<int, int>> q;
        q.emplace(0, 0);
        visited[0] = true;
        while (q.size()) {
            auto [cur, step] = q.front();
            q.pop();
            for (int i = 0; i < 8; ++i) {
                auto nxt = [](int i, int j) -> int {
                    string s = to_string(i);
                    while(s.size() < 4){
                        s = "0"+s;
                    }
                    if (j & 1)
                        s[j / 2] = s[j / 2] == '9' ? '0' : s[j / 2] + 1;
                    else
                        s[j / 2] = s[j / 2] == '0' ? '9' : s[j / 2] - 1;
                    return stoi(s);
                }(cur, i);
                if (!visited[nxt]) {
                    if (nxt == e) {
                        return step + 1;
                    }
                    visited[nxt] = true;
                    q.emplace(nxt, step + 1);
                }
            }
        }
        return -1;
    }
};
// @lc code=end
