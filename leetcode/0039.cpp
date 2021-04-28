class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> ans;
        int n = candidates.size();
        auto dfs = [&](auto&& dfs, auto target, auto i) {
            if (i == n) {
                return;
            }
            if (target == 0) {
                ans.emplace_back(tmp);
                return;
            }
            dfs(dfs, target, i + 1);
            if (target >= candidates[i]) {
                tmp.emplace_back(candidates[i]);
                dfs(dfs, target - candidates[i], i);
                tmp.pop_back();
            }
        };
        dfs(dfs, target, 0);
        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        vector<vector<int>> ans;
        int n = candidates.size();
        auto dfs = [&](auto&& dfs, auto target, auto i) {
            if (target == 0) {
                ans.emplace_back(tmp);
                return;
            }
            for (auto j = i; j < n && target >= candidates[j]; j++) {
                tmp.emplace_back(candidates[j]);
                dfs(dfs, target - candidates[j], j);
                tmp.pop_back();
            }
        };
        sort(candidates.begin(), candidates.end());
        dfs(dfs, target, 0);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> dp[1000], res;

    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        dp[0].push_back(vector<int>());
        for (auto w : c)
            for (int j = w; j <= target; ++j)
                if (dp[j - w].empty() == 0) {
                    auto tmp = dp[j - w];
                    for (auto& ea : tmp) {
                        ea.push_back(w);
                        dp[j].push_back(ea);
                    }
                }
        res = dp[target];
        for (auto& i : res) {
            sort(i.begin(), i.end());
        }
        return res;
    }
};