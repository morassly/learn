class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n) {
            return -1;
        }
        int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
        while (l < r) {
            int mid = l + (r - l) / 2;
            if ([&](int limit) {
                    int flower = 0, res = 0;
                    for (auto& each : bloomDay) {
                        if (each <= limit)
                            flower++;
                        else
                            flower = 0;
                        if (flower == k) {
                            res++;
                            flower = 0;
                        }
                    }
                    if (res >= m) return true;
                    return false;
                }(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};