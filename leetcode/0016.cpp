class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        if (nums.size() == 3)
            return ans;
        for (int i = 0; i < nums.size() - 2; ++i)
        {
            if (i == 0 || nums[i] != nums[i - 1])
            {
                int l = i + 1, r = nums.size() - 1;
                while (l < r)
                {
                    if (abs(nums[i] + nums[l] + nums[r] - target) < abs(ans - target))
                        ans = nums[i] + nums[l] + nums[r];
                    if (nums[i] + nums[l] + nums[r] < target)
                        l++;
                    else if (nums[i] + nums[l] + nums[r] > target)
                        r--;
                    else
                    {
                        return target;
                    }
                }
            }
        }
        return ans;
    }
};