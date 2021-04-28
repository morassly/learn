class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> s1(nums1), s2(nums2);
        if (m > n) {
            swap(m, n);
            swap(s1, s2);
        }

        int l = 0, r = m;
        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = (m + n + 1) / 2 - i;
            if (i < m && s1[i] < s2[j - 1])
                l = i + 1;
            else if (i > 0 && s1[i - 1] > s2[j])
                r = i - 1;
            else {
                cout << i << ' ' << j << endl;
                double ans = 0.0;
                if (i == 0)
                    ans = s2[j - 1];
                else if (j == 0)
                    ans = s1[i - 1];
                else
                    ans = max(s1[i - 1], s2[j - 1]);
                cout << ans << endl;
                if ((m + n) & 1) return ans;
                if (i == m)
                    ans += s2[j];
                else if (j == n)
                    ans += s1[i];
                else
                    ans += min(s1[i], s2[j]);
                return ans / 2.0;
            }
        }
        return 0.0;
    }
};