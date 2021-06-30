/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ret = 0, n = points.size();
        for(int i = 0; i < n; ++i){
            if (ret > n-i || ret > n/2)
                break;
            unordered_map<double,int> m;
            for(int j = i +1; j < n; ++j){
                if(points[i][0] == points[j][0]){
                    m[INT_MAX]++;
                } else {
                    double temp = double(points[i][1]-points[j][1]) / double(points[i][0] - points[j][0]);
                    m[temp]++;
                }
            }
            for(auto it : m){
                ret = max(ret,it.second);
            }
        }
        return ret + 1;
    }
};
// @lc code=end

