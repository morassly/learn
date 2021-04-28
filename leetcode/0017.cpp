class Solution {
public:
    unordered_map<char, string> table{{'2', "abc"}, {'3', "def"}, {'4', "ghi"},
                                      {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
                                      {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> letterCombinations(string d) {
        vector<string> ans;
        if (d == "") return ans;
        std::function<void(int, string)> dfs;
        dfs = [&](int index, string temp) {
            if (index == d.size()) {
                ans.push_back(temp);
                return;
            }
            string t = table[d[index]];
            for (auto c : t) dfs(index + 1, temp + c);
            return;
        };
        dfs(0, "");
        return ans;
    }
};