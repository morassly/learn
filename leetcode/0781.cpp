class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int count[1001];
        fill(count, count + 1001, 0);
        for (auto& i : answers) {
            count[i + 1]++;
        }
        int ans = 0;
        for (auto i = 1; i < 1001; i++) {
            ans += (count[i] + i - 1) / i * i;
        }
        return ans;
    }
};