class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) return "";
        string tmin = strs[0], tmax = strs[0];
        for (auto i : strs) {
            tmin = min(tmin, i);
            tmax = max(tmax, i);
        }
        int i = 0;
        for (; i < tmin.length() && tmin[i] == tmax[i]; ++i) {
        }
        return tmin.substr(0, i);
    }
};