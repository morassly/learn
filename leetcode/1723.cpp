class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> tot(1 << n, 0);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);
            tot[i] = tot[y] + jobs[x];
        }

        vector<vector<int>> dp(k, vector<int>(1 << n));
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = tot[i];
        }
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < (1 << n); j++) {
                int minn = INT_MAX;
                for (int x = j; x; x = (x - 1) & j) {
                    minn = min(minn, max(dp[i - 1][j - x], tot[x]));
                }
                dp[i][j] = minn;
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};

class Solution1 {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> tot(1 << n, 0);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);
            tot[i] = tot[y] + jobs[x];
        }

        int l = *max_element(jobs.begin(), jobs.end());
        int r = accumulate(jobs.begin(), jobs.end(), 0);
        while (l < r) {
            int mid = l + (r - l) / 2;
            vector<int> dp(1 << n, INT_MAX / 2);
            dp[0] = 0;
            for (int i = 1; i < (1 << n); i++) {
                for (int s = i; s; s = (s - 1) & i) {
                    if (tot[s] <= mid) {
                        dp[i] = min(dp[i], dp[i - s] + 1);
                    }
                }
            }
            if (dp[(1 << n) - 1] > k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};