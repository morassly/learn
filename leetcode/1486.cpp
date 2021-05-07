class Solution {
public:
    int xorOperation(int n, int start) {
        auto sumXor = [](int x) {
            switch (x % 4) {
            case 0:
                return x;
            case 1:
                return 1;
            case 2:
                return x + 1;
            default:
                return 0;
            }
        };
        int s = start >> 1, e = start & n & 1;
        int ret = sumXor(s - 1) ^ sumXor(s + n - 1);
        return ret << 1 | e;
    }
};