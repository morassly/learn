#include <iostream>
#include <vector>

using namespace std;
struct Trie{
    Trie* l,*r;
    Trie():l(nullptr),r(nullptr){}
};
class Solution {
    Trie* root = new Trie();
    constexpr static int K = 30;
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++){
            insert(nums[i]);
            ans = max(ans, search(nums[i+1]));
        }
        return ans;
    }
    void insert(int x){
        auto cur = root;
        for(auto k = K;k;k--){
            if(auto temp = (x>>k) & 1;temp){
                if (cur->r == nullptr)
                    cur->r = new Trie();
                cur = cur->r;
            } else {
                if (cur->l == nullptr)
                    cur->l = new Trie();
                cur = cur->r;
            }
        }
    }
    int search(int x) {
        auto cur = root;
        int ans = 0;
        for(auto k = K;k;k--){
            if(auto temp = (x>>k) & 1;temp){
                if (cur->l != nullptr){
                    cur = cur->l;
                    ans = (ans<<1) | 1;
                } else {
                    cur = cur->r;
                    ans <<= 1;
                }    
            } else {
                if (cur->r != nullptr){
                    cur = cur->r;
                    ans = (ans<<1) | 1;
                } else {
                    cur = cur->l;
                    ans <<= 1;
                } 
            }
        }
        return ans;
    }
};