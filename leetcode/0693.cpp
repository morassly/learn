class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        unsigned int tmp = n ^ (n >> 1);
        return !(n & (n + 1));
    }
};