class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (auto& num : nums){
            a = ~b & (a ^ num);
            b = ~a &  (b ^ num);
        }
        return a;
    }
};