class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.size(), m = num2.size();
        vector<int> ans(m + n, 0);
        for (int i = n - 1; i >= 0; i--) {
            auto x = num1[i] - '0';
            for (int j = m - 1; j >= 0; j--) {
                auto y = num2[j] - '0';
                ans[i + j + 1] += x * y;
                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] %= 10;
            }
        }
        // for_each(ans.begin(),ans.end(),[](const int& i){cout<<i<<endl;});
        string anss;
        int i = 0;
        if (!ans[0]) {
            i = 1;
        }
        for (; i < m + n; i++) {
            anss.push_back(ans[i] + '0');
        }
        return anss;
    }
};