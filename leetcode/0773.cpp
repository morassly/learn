/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <stack>
using namespace std;
// @lc code=start
class Solution {
    const vector<int> dir[6] = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s = "", e = "123450";
        for(auto &i : board)
            for(auto &j : i)
                s += (j+'0');
        if (s == e) return 0;
        auto get_nxt = [&](string& s) -> vector<string> {
            vector<string> ans;
            int ind = s.find('0');
            for(auto i : dir[ind]){
                swap(s[ind],s[i]);
                ans.push_back(s);
                swap(s[ind],s[i]);
            }
            return ans;
        };
        unordered_map<string,int> vis;
        queue<string> q;q.emplace(s);
        vis[s] = 1;
        while(!q.empty()){
            string cur = q.front();q.pop();
            for(auto&& nxt : get_nxt(cur)){
                if(int step = vis[cur];!vis[nxt]){
                    if(nxt == e){
                        return step;
                    }
                    q.emplace(nxt);
                    vis[nxt] = step + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

