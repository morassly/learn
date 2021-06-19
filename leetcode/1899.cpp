class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int x = target[0], y = target[1], z = target[2];
        int a = 0, b = 0, c = 0;

        for (const auto& triplet : triplets) {
            int ai = triplet[0], bi = triplet[1], ci = triplet[2];
            if (ai <= x && bi <= y && ci <= z) {
                tie(a, b, c) = tuple{max(a, ai), max(b, bi), max(c, ci)};
            }
        }

        return tie(a, b, c) == tie(x, y, z);
    }
};
