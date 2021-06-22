/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 60; ++j) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                    string temp = "";
                    temp += to_string(i);
                    temp += ":";
                    if (j < 10) {
                        temp += '0';
                    }
                    temp += to_string(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
