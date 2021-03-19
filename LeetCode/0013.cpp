class Solution
{
public:
    int num[256];
    int romanToInt(string s)
    {
        num['I'] = 1;
        num['V'] = 5;
        num['X'] = 10;
        num['L'] = 50;
        num['C'] = 100;
        num['D'] = 500;
        num['M'] = 1000;
        long ans = 0;
        for (auto i = 0; i < s.length() - 1; i++)
            if (num[s[i]] >= num[s[i + 1]])
                ans += num[s[i]];
            else
                ans -= num[s[i]];
        return ans += num[s[s.length() - 1]];
    }
};