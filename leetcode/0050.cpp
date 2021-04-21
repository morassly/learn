class Solution {
public:

    double myPow(double x, int n) {
        if (!n)
            return 1.0;
        auto q_pow = [&x](long long n){
            auto ans = 1.0;
            while(n){
                if (n&1)
                    ans *= x;
                x *=x;
                n >>= 1;
            }
            return ans;
        };
        long N = n;
        if (n < 0){
            return 1.0/q_pow(-N);
        }
        return q_pow(N);
    }
};