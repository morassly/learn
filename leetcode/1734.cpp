#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1;
        vector ans(n, 0);
        for (int i = 1; i <= n; i++) ans[0] ^= i;
        for (int i = 1; i < n - 1; i += 2) ans[0] ^= encoded[i];
        for (int i = 0; i < n - 1; i++) ans[i + 1] = ans[i] ^ encoded[i];
        return ans;
    }
};