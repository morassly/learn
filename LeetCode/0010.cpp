class Solution1
{
public:
    bool match(string::iterator sb, string::iterator se, string::iterator pb, string::iterator pe)
    {
        if (sb == se && pb == pe)
            return true;
        if (sb != se && pb == pe)
            return false;

        if (*(pb + 1) == '*')
            if (match(sb, se, pb + 2, pe))
                return true;
        if (*sb == *pb || (*pb == '.' && sb != se))
        {
            if (*(pb + 1) == '*')
                if (match(sb + 1, se, pb, pe))
                    return true;
            return match(sb + 1, se, pb + 1, pe);
        }
        return false;
    }
    bool isMatch(string s, string p)
    {
        return match(s.begin(), s.end(), p.begin(), p.end());
    }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        auto match = [&](int i, int j) {
            if (i == 0)
            {
                return false;
            }
            if (p[j - 1] == '.')
            {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };
        dp[0][0] = 1;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (p[j - 1] == '*')
                {
                    dp[i][j] |= dp[i][j - 2];
                    if (match(i, j - 1))
                        dp[i][j] |= dp[i - 1][j];
                }
                else
                {
                    if (match(i, j))
                        dp[i][j] |= dp[i - 1][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};
