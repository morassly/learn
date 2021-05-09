class Solution {
    static constexpr int INF = 0x3f3f3f3f;
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> tot(1 << n, 0);
        for (int i = 1; i < (1 << n); i++) {
            int x = __builtin_ctz(i), y = i - (1 << x);
            tot[i] = tot[y] + jobs[x];
        }

        vector<vector<int>> dp(k, vector<int>(1 << n,INF));
        for (int i = 0; i < (1 << n); i++) {
            dp[0][i] = tot[i];
        }
        for (int i = 1; i < k; i++) {
            for (int j = 0; j < (1 << n); j++) {
                for (int x = j; x; x = (x - 1) & j) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j - x], tot[x]));
                }
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

class Solution2 {
public:
    bool check(vector<int>& jobs, int mid, int k) {
        int n = jobs.size();
        vector<int> loads(k, 0);
        auto dfs = [&](auto&& dfs, int idx) {
            if (idx == n) {
                return true;
            }
            for (auto& load : loads) {
                if (load + jobs[idx] <= mid) {
                    load += jobs[idx];
                    if (dfs(dfs, idx + 1))
                        return true;
                    load -= jobs[idx];
                }
                if (load == 0 || load + jobs[idx] == mid)
                    break;
            }
            return false;
        };
        return dfs(dfs, 0);
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        int l = *max_element(jobs.begin(), jobs.end());
        int r = accumulate(jobs.begin(), jobs.end(), 0);
        while (l < r) {
            int mid = l + (r - l) / 2;

            if (!check(jobs, mid, k)) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};