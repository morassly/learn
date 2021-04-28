class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; ++i) {
            string ret = "";
            int l = 0, r = 1;
            while (r < str.size()) {
                if (str[l] != str[r]) {
                    ret.push_back(r - l + '0');
                    ret.push_back(str[l]);
                    l = r;
                }
                r++;
            }
            ret.push_back(r - l + '0');
            ret.push_back(str[l]);
            str = ret;
        }

        return str;
    }
};