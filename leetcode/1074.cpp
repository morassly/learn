class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size(), ans = 0;
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n, 0);
            for (int j = i; j < m; ++j) {
                unordered_map<int, int> cnt;
                int presum = 0;
                for (int k = 0; k < n; ++k) {
                    ++cnt[presum];
                    sum[k] += matrix[j][k];
                    presum += sum[k];
                    if (cnt.count(presum - target)) {
                        ans += cnt[presum - target];
                    }
                }
            }
        }
        return ans;
    }
};