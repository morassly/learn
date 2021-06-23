/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        if (maxWidth == 0) return {""};
        int i = 0, j = 0;
        int n = words.size();
        while (j != n) {
            int len = -1;
            while (j < n && len + words[j].size() + 1 <= maxWidth)
                len += words[j++].size() + 1;
            int space = maxWidth - len + j - i - 1;
            int k = i;
            while (space) {
                words[k++] += " ";
                space--;
                if (j != n && (k == j - 1 || k == j)) k = i;
                if (j == n && k == j) k = j - 1;
            }
            string line = "";
            for (int l = i; l < j; ++l)
                line += words[l];
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};
// @lc code=end
