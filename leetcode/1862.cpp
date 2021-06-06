class Solution {
    static constexpr int MOD = 1e9 + 7;

public:
    int sumOfFlooredPairs(vector<int>& nums) {
        static auto _ = []() {
            ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return 0;
        }();
        int maxnum = *max_element(nums.begin(), nums.end());

        vector<int> cnt(maxnum + 1, 0);
        for (auto&& num : nums)
            ++cnt[num];
        vector<int> pre(maxnum + 2);
        for (auto i = maxnum; i >= 0; --i) {
            pre[i] = pre[i + 1] + cnt[i];
            //cout<<pre[i] <<" ";
        }

        long long ans = 0;
        for (int i = 1; i <= maxnum; ++i)
            if (cnt[i]) {
                for (int j = 1; i * j <= maxnum; j++) {
                    ans = (ans + (long long)cnt[i] * pre[i * j]) % MOD;
                }
            }
        return ans;
    }
};