/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        for(auto &&i : intervals){
            if(!ans.size() || ans.back()[1] < i[0]){
                ans.push_back(i);
            } else {
                ans.back()[1] = max(i[1],ans.back()[1]);
            }
        }
        return ans;
    }
};
// @lc code=end

