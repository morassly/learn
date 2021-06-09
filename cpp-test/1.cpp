#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int lastStoneWeightII(vector<int>& stones) {
    int sum = accumulate(stones.begin(),stones.end(),0);
    int t = sum/2;
    int dp[t+1];
    memset(dp,0,sizeof dp);
    for(auto stone : stones){
        for(int i = t; i >= stone; --i){
            dp[i] = max(dp[i],dp[i-stone]+stone);
        }
    }
    return dp[t];
}
int main() {
    return 0;
}