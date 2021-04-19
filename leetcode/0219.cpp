class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        auto n = nums.size();
        if(k == 0)
            return false;
        unordered_set s={nums[0]};
        for(int i = 1; i < n;i++){
            if(s.count(nums[i]))
                return true;
            s.emplace(nums[i]);
            if (i >= k)
                s.erase(nums[i-k]);
        }
        return false;
    }
};