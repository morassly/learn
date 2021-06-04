class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        auto decode = [](string& s) {
            int ret = 0;
            for (auto&& c : s) {
                ret += (c - 'a');
                ret *= 10;
            }
            return ret;
        };

        return decode(firstWord) + decode(secondWord) == decode(targetWord);
    }
};
