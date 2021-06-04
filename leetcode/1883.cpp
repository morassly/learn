class Solution {
private:
    using LL = long long;

public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size();
        vector<LL> f(n + 1, LLONG_MAX / 2);
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j >= 0; --j) {
                LL temp = LLONG_MAX / 2;
                if (j != i) {
                    temp = min(temp, ((f[j] + dist[i - 1] - 1) / speed + 1) * speed);
                }
                if (j != 0) {
                    temp = min(temp, f[j - 1] + dist[i - 1]);
                }
                f[j] = temp;
            }
        }
        for (int j = 0; j <= n; ++j) {
            if (f[j] <= (LL)hoursBefore * speed) {
                return j;
            }
        }
        return -1;
    }
};
