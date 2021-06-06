class Solution {
public:
    string sortSentence(string s) {
        vector<string> arr(9);
        string tmp = "";
        int n = 0;

        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                arr[c - '0' - 1] = tmp;
                tmp.clear();
                ++n;
            } else if (c != ' ') {
                tmp.push_back(c);
            }
        }
        string res = arr[0];
        for (int i = 1; i < n; ++i) {
            res += " " + arr[i];
        }
        return res;
    }
};