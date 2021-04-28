class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> m;
        int ans = 0;
        for (auto& word : words) {
            int mask = 0, length = word.size();
            for (auto& ch : word) {
                mask |= 1 << (ch - 'a');
            }
            m[mask] = max(m[mask], length);
            for (auto& [h_mask, h_len] : m) {
                if (!(h_mask & mask)) {
                    ans = max(ans, length * h_len);
                }
            }
        }
        return ans;
    }
};