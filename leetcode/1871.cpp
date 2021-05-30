class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        if (s[n - 1] != '0') return false;
        int cnt = 1;
        vector<bool> dp(n, false);
        dp[0] = true;
        for (int i = minJump; i < n; ++i) {
            if (s[i] == '0' && cnt)
                dp[i] = true;
            if (i >= maxJump && dp[i - maxJump])
                --cnt;
            if (dp[i - minJump + 1])
                ++cnt;
        }
        return dp[n - 1];
    }
};