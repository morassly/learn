class Solution {
public:
    int minSwaps(string s) {
        int s0n0 = 0, s0n1 = 0;
        int s1n0 = 0, s1n1 = 0;
        for (int c = 0; c < s.size(); c++) {
            if (c % 2 == 0) {
                if (s[c] != '0')
                    s0n0++;  //对于s0来说，这个位得是0
                else
                    s1n1++;  //对于s1来说，这个位得是1
            } else {
                if (s[c] != '1')
                    s0n1++;  //对于s0来说，这个位得是1
                else
                    s1n0++;  //对于s1来说，这个位得是0
            }
        }
        if (s0n0 != s0n1 && s1n0 != s1n1) return -1;    // s0 s1 都换不了，返回-1
        if (s0n0 == s0n1 && s1n0 != s1n1) return s0n0;  // s0 换得了，返回s0
        if (s0n0 != s0n1 && s1n0 == s1n1) return s1n0;  // s1 换得了，返回s1
        return min(s0n0, s1n0);                         // 两个都换得了，返回交换次数较少的那个。
    }
};