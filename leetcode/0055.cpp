/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n ==  1)    return true;
        int mx = 0;
        for(int i  = 0; i < n - 1; ++i){
            if (i <= mx){
                mx = max(mx, i + nums[i]);
                if (mx >= (n-1) ) return true;
            }
        }
        return false;
    }
};
// @lc code=end
