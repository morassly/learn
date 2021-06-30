/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        auto dfs =[&](auto&& dfs,int pos){
            if(tmp.size() == k){
                ans.push_back(tmp);
                return ;
            }
            if(pos > n) return;
            for(int i = pos; i <= n; ++i){
                tmp.push_back(i);
                dfs(dfs,i+1);
                tmp.pop_back();
            }
        };
        dfs(dfs,1);
        return ans;
    }
};
// @lc code=end

