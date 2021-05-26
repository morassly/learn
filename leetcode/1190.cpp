class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> pair(n);
        stack<int> stk;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                pair[i] = j, pair[j] = i;
            }
        }

        string ret;
        int index = 0, step = 1;
        while (index < n) {
            if (s[index] == '(' || s[index] == ')') {
                index = pair[index];
                step = -step;
            } else {
                ret.push_back(s[index]);
            }
            index += step;
        }
        return ret;
    }
};