/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string res, s;
        stack<string>stk;
        stringstream ss(path);
        while(getline(ss, s, '/')) {
            if (s == "" || s == ".") continue;
            if (s == ".." && !stk.empty()) stk.pop();
            else if (s != "..") stk.push(s);
        }
        while(!stk.empty()){
            res = "/"+ stk.top() + res;
            stk.pop();
        }
        return res.empty() ? "/" : res;
    }
};
// @lc code=end

