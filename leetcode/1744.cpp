class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = candiesCount.size();
        using ll = long long;
        vector<ll> sum(n, 0);
        sum[0] = candiesCount[0];
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + candiesCount[i];
        vector<bool> ans;
        for (auto q : queries) {
            ll t = q[0], d = q[1], c = q[2];
            ll cand_min = d + 1, cand_max = (ll)c * (d + 1);
            ll type_min = t == 0 ? 1 : sum[t - 1] + 1;
            ll type_max = sum[t];
            ans.push_back(cand_min <= type_max && cand_max >= type_min);
        }
        return ans;
    }
};
static int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();