class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int temp = x ^ y, ans = 0;
        while (temp)
        {
            ans++;
            temp &= (temp - 1);
        }
        return ans;
    }
};