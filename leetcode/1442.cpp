#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int countTriplets(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> cnt, tot;
        int ans = 0, s = 0;
        for (int k = 0; k < n; k++) {
            int val = s ^ arr[k];
            if (cnt.count(val))
                ans += cnt[s] * k - tot[s];
            ++cnt[s];
            tot[s] += k;
            s = val;
        }
        return ans;
    }
};
