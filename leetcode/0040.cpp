class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        auto dfs = [&](auto&& dfs, auto ispre, auto idx, auto target) {
            if (target == 0) {
                ans.emplace_back(tmp);
                return;
            }
            if (idx == candidates.size()) return;
            dfs(dfs, false, idx + 1, target);
            if (idx && !ispre && candidates[idx] == candidates[idx - 1]) return;
            if (target >= candidates[idx]) {
                tmp.emplace_back(candidates[idx]);
                dfs(dfs, true, idx + 1, target - candidates[idx]);
                tmp.pop_back();
            }
        };
        dfs(dfs, false, 0, target);
        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        auto dfs = [&](auto&& dfs, auto idx, auto target) {
            if (target == 0) {
                ans.emplace_back(tmp);
                return;
            }
            for (auto i = idx; i < candidates.size() && target >= candidates[i];
                 i++) {
                if (i > idx && candidates[i] == candidates[i - 1]) continue;
                tmp.emplace_back(candidates[i]);
                dfs(dfs, i + 1, target - candidates[i]);
                tmp.pop_back();
            }
        };
        dfs(dfs, 0, target);
        return ans;
    }
};
// dp 01背包
class Solution3 {
public:
    vector<vector<int>> dp[1000], res;

    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        dp[0].push_back(vector<int>());
        for (auto w : c)
            for (int j = target; j >= w; --j)
                if (dp[j - w].empty() == 0) {
                    auto tmp = dp[j - w];
                    for (auto& ea : tmp) {
                        ea.push_back(w);
                        dp[j].push_back(ea);
                    }
                }
        res = dp[target];
        set<vector<int>> S;
        for (auto& i : res) {
            sort(i.begin(), i.end());
            S.insert(i);
        }
        res.clear();
        for (auto& i : S) res.push_back(i);
        return res;
    }
};