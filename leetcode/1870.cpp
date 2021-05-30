class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        long long t = llround(hour * 100);
        using ll = long long;
        if ((ll)(n - 1) * 100 >= t)
            return -1;
        int l = 1, r = 1e7;
        while (l < r) {
            int mid = l + (r - l) / 2;
            ll temp = 0;
            for (int i = 0; i < n - 1; i++) {
                temp += (long long)(dist[i] + mid - 1) / mid;
            }
            if ((temp * mid + dist[n - 1]) * 100 > t * mid) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};