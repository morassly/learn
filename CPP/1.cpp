#include <iostream>
#include <vector>
using namespace std;
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    vector<int> s1(nums1), s2(nums2);
    if (m > n)
    {
        swap(m, n);
        swap(s1, s2);
    }

    int left = 0, right = m + 1, tol = m + n + 1, i = 0, j = 0, ans1 = 0, ans2 = 0;
    while (left < right)
    {
        i = left + (right - left)/2;
        j = tol/2 - i;

        int min1 = i == 0 ? INT_MIN : s1[i - 1];
        int max1 = i == m ? INT_MAX : s1[i];
        int min2 = j == 0 ? INT_MIN : s2[j - 1];
        int max2 = j == n ? INT_MAX : s2[j];

        if (min1 < max2)
        {
            left = i + 1;
            ans1 = max(min1, min2);
            ans2 = min(max1, max2);
        }
        else
            right = i;
    }
    if ((m + n) & 1)
        return ans1;
    return (ans1 + ans2) / 2.0;
    
}
int main()
{
    vector<int> a = {1, 3}, b = {2};
    printf("%f", findMedianSortedArrays(a, b));
    int txt;
    cin >> txt;
    return 0;
}