class Solution {
public:
    bool nextPermutation(vector<int>& nums) {
        if (nums.empty()) return false;
        auto it = nums.rbegin() + 1;
        for ( ; it != nums.rend(); it++)
            if (*it < *(it-1)) {
                auto it0 = upper_bound(nums.rbegin(), it, *it);
                swap(*it, *it0);
                reverse(nums.rbegin(), it);
                return true;
            }
        reverse(nums.rbegin(), it);
        return false;
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> all_perm;
        do all_perm.push_back(nums); while (nextPermutation(nums));
        return all_perm;
    }
};

class Solution {
public:
    void DFS(vector<vector<int>>& res, vector<int> nums, int pos){
        if(pos == nums.size() - 1){
            res.push_back(nums);
            return;
        }
        for(int i = pos; i < nums.size(); i++){
            if(i!=pos&&nums[i]==nums[pos]) continue;
            
            swap(nums[pos], nums[i]);
            DFS(res, nums, pos + 1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        DFS(res, nums, 0);
        return res; 
    }
};