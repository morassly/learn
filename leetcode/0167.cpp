class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int l = 0, r = numbers.size() - 1;
        while (l < r)
        {
            if (auto tmp = numbers[l] + numbers[r]; tmp == target)
            {
                return {l + 1, r + 1};
            }
            else if (tmp < target)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return {-1, -1};
    }
};