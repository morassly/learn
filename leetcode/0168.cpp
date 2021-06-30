class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ret = "";
        while(columnNumber--){
            ret = string(1,columnNumber%26 + 'A') + ret;
            columnNumber /= 26;
        }
        return ret;
    }
};