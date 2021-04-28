class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        std::function<void(string, int, int)> dfs;
        dfs = [&](string temp, int l, int r) {
            if (!l && !r) ans.push_back(temp);
            if (l > 0) dfs(temp + "(", l - 1, r);
            if (l < r) dfs(temp + ")", l, r - 1);
        };
        dfs("", n, n);
        return ans;
    }
};

class Solution1 {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> dp;
        if (n == 0)
            return {};
        else if (n == 1)
            return {"()"};
        dp.push_back({""}), dp.push_back({"()"});
        for (int i = 2; i <= n; ++i) {
            vector<string> temp;
            for (int j = 0; j < i; ++j) {
                for (auto s1 : dp[j])
                    for (auto s2 : dp[i - 1 - j]) {
                        temp.push_back('(' + s1 + ')' + s2);
                    }
            }
            dp.push_back(temp);
        }
        return dp[n];
    }
};