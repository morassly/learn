/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, j = i, k = nums.size() - 1;
        
        while(j <= k){
            if(nums[j] == 0) swap(nums[i++], nums[j++]);
            else if(nums[j] == 1) j++;
            else swap(nums[k--], nums[j]);
        }
    }
};
// @lc code=end

