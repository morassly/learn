class Solution {
public:
    int clumsy(int n) {
        int ans[5] = {0,1,2,6,7};
        if (n <= 4) return ans[n];
        if (n%4 == 0)
            return n + 1;
        else if (n%4 <= 2)
            return  n + 2;
        else return n - 1;
    }
};