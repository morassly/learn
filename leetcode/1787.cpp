#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
    constexpr static int INF = 0x3f3f3f3f;
    constexpr static int N = 1024;

public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(N, INF);
        dp[0] = 0;
        int ans = 0, minv = INF;
        for (int i = 0; i < k; i++) {
            unordered_map<int, int> cnt;
            int len = 0, maxv = 0;
            for (int j = i; j < n; j += k) {
                maxv = max(maxv, ++cnt[nums[j]]);
                ++len;
            }
            ans += len - maxv;
            minv = min(minv, maxv);
            vector<int> dp1(N, INF);
            for (int j = 0; j < N; j++) {
                for (auto& [x, c] : cnt)
                    dp1[j] = min(dp1[j], dp[j ^ x] - c + len);
            }
            dp = move(dp1);
        }
        return min(ans + minv, dp[0]);
    }
};