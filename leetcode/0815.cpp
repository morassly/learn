/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] 公交路线
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
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int n = routes.size();
        unordered_map<int,vector<int>> m;
        vector<int> dis(n,-1);
        queue<int> q;
        for(int i = 0; i < n; ++i){
            for(auto site : routes[i]){
                if(site == source){
                    dis[i] = 1;
                    q.push(i);
                }
                m[site].push_back(i);
            }
        }

        while(!q.empty()){
            auto bus = q.front();q.pop();
            int step = dis[bus];
            for(auto site : routes[bus]){
                if (site == target) return step;
                //cout<< site<<endl;
                for(auto nxtbus : m[site]){
                    if(dis[nxtbus] == -1){
                        dis[nxtbus] = step + 1;
                        q.push(nxtbus);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

