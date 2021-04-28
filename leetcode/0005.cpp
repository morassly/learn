class Solution {
public:
    string longestPalindrome(string s) {
        string temp = "$#";
        for (auto i : s) {
            temp += i;
            temp += '#';
        }
        temp += '@';

        int ansCenter = 0, ansLen = 0;
        int* p = new int[temp.size()]();
        for (int i = 1, center = 0, mx = 0; i < temp.size() - 1; ++i) {
            p[i] = mx > i ? min(p[2 * center - i], mx - i) : 0;
            while (temp[i + p[i] + 1] == temp[i - p[i] - 1]) ++p[i];
            if (mx < i + p[i]) {
                mx = i + p[i];
                center = i;
            }
            if (ansLen < p[i]) {
                ansLen = p[i];
                ansCenter = i;
            }
        }
        return s.substr((ansCenter - ansLen) / 2, ansLen);
    }
};