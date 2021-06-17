class Solution {
public:
    int countSubstrings(string s) {
        string temp = "$#";
        for (auto c : s) {
            temp += c;
            temp += '#';
        }
        temp += '@';

        int ans = 0, n = temp.size();
        int p[n];
        for (int i = 1, center = 0, mx = 0; i < n - 1; ++i) {
            p[i] = (i < mx) ? min(p[2 * center - i], mx - i) : 0;
            while (temp[i + p[i] + 1] == temp[i - p[i] - 1]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                center = i;
            }
            ans += (p[i] + 1) / 2;
        }
        return ans;
    }
};