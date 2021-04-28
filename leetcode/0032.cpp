class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> ss;
        ss.emplace(-1);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                ss.emplace(i);
            } else {
                ss.pop();
                if (ss.empty()) {
                    ss.emplace(i);
                } else {
                    ans = max(ans, i - ss.top());
                }
            }
        }
        return ans;
    }
};