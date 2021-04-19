class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto& i: nums)
            if(s.count(i)) return true;
            else s.insert(i);
        return false;
    }
};