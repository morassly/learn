#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0)
            return 0;

        int next[needle.size()];
        next[0] = -1;
        int i=0, j=-1;
        while(i<needle.size()-1){
            if(j==-1 || needle[i]==needle[j]){
                next[++i] = ++j;
                if(needle[i] == needle[j])
                    next[i] = next[j];
            }else{
                j = next[j];
            }
        }

        i = 0, j = 0;
        // int m = haystack.size(),n = needle.size();
        while(i < haystack.size() && j < needle.size()) {

            if(j ==  -1 || haystack[i] == needle[j]){
                ++i;
                ++j;
            }else{
                j = next[j];
            }
        }

        if(j == needle.size())
            return i-j;
        else
            return -1;
    }
};

int main(){
    Solution s;
    string a ="hello",t="ll";
   cout<<s.strStr(a,t)<<endl;
    return 0;
}