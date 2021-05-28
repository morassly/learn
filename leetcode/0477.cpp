class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < 30; i++) {
            int c = 0;
            for (auto& each : nums)
                if ((each >> i) & 1)
                    ++c;
            ans += c * (n - c);
        }
        return ans;
    }
};