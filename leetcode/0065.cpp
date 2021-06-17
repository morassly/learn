class Solution {
public:
    bool isNumber(string s) {
        int n = s.size(), idx = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (idx == -1)
                    idx = i;
                else
                    return false;
            }
        }
        auto check = [&](int l, int r, bool must_int) -> bool {
            if (l >= r) return false;
            if (s[l] == '-' || s[l] == '+') ++l;
            bool hasdot = false, hasnum = false;
            for (int i = l; i < r; ++i) {
                if (s[i] == '.') {
                    if (must_int || hasdot) return false;
                    hasdot = true;
                } else if ('0' <= s[i] && s[i] <= '9') {
                    hasnum = true;
                } else {
                    return false;
                }
            }
            return hasnum;
        };

        bool ans = true;
        if (idx != -1) {
            ans &= check(0, idx, false);
            ans &= check(idx + 1, n, true);
        } else {
            ans &= check(0, n, false);
        }
        return ans;
    }
};