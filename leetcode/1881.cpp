class Solution {
public:
    string maxValue(string s, int x) {
        auto X = x + '0';
        int i = 0, n = s.size();
        if (s[i] == '-') {
            for (; i < n && s[i] <= X; ++i)
                ;
        } else {
            for (; i < n && s[i] >= X; ++i)
                ;
        }
        s.insert(i, 1, X);
        return s;
    }
};