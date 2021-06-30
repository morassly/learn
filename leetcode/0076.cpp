/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
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
    string minWindow(string s, string t) {
        int cnt[128];
        memset(cnt,0,sizeof cnt);
        for(auto c: t) cnt[c]++;

        int l = 0, r = 0,n = s.size();
        int len = 0, nt = t.size();
        int L = -1,ansL=INT_MAX;
        while(r < n){
            if(cnt[s[r++]]-- > 0) ++len;

            while(len == nt){
                if(r-l < ansL){
                    ansL = r - l;
                    L = l;
                }
                if(++cnt[s[l++]] > 0) --len;
            }
        }
        return L == -1 ? "":s.substr(L,ansL);
    }
};
// @lc code=end

