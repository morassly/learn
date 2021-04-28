class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> strs(n);
        transform(nums.begin(), nums.end(), strs.begin(),
                  [](int& x) { return to_string(x); });
        sort(strs.begin(), strs.end(),
             [](string& a, string& b) { return a + b > b + a; });
        auto ans = accumulate(strs.begin(), strs.end(), string());
        if (ans[0] == '0') return "0";
        return ans;
    }
};