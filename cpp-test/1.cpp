#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int maxLength(vector<string>&& arr) {
    int n = arr.size();
    int masks[n];
    for (int i = 0; i < n; i++) {
        int m = 0;
        for (auto c : arr[i]) {
            if ((m >> (c - 'a')) & 1) {
                m = 0;
                break;
            }
            m |= (1 << (c - 'a'));
        }
        masks[i] = m;
    }
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int temp = 0;
        for (int mask = i; mask != 0; mask &= (mask - 1)) {
            int j = mask & (-mask);
            if ((temp & masks[j]) == 0) {
                temp |= masks[j];
            } else {
                temp = 0;
                break;
            }
        }
        ans = max(ans, __builtin_popcount(temp));
    }
    return ans;
}
int main() {
    
    cout << maxLength({"un","iq","ue"}) << endl;
    return 0;
}