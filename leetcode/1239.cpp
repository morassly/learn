class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int masks[n];
        for(int i = 0; i < n; i++){
            int m = 0;
            for(auto c : arr[i]){
                if((m >> (c- 'a')) & 1){
                    m = 0;
                    break;
                }
                m |= (1 << (c-'a'));
            }
            masks[i] = m;
        }
        int ans = 0;
        for(int i = 0; i < (1<<n);++i){
            int temp = 0;
            for(int mask = i;mask;mask &= (mask-1)){
                int j = __builtin_ctz(mask & (-mask));
                if((temp & masks[j]) == 0){
                    temp |= masks[j];
                } else {
                    temp = 0;
                    break;
                }
            }
            ans = max(ans,__builtin_popcount(temp));
        }
        return ans;
    }
};
class Solution1 {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int masks[n];
        for(int i = 0; i < n; i++){
            int m = 0;
            for(auto c : arr[i]){
                if((m >> (c- 'a')) & 1){
                    m = 0;
                    break;
                }
                m |= (1 << (c-'a'));
            }
            masks[i] = m;
        }
        int ans = 0;
        auto dfs = [&](auto&& dfs,int len,int mask){
            ans = max(ans,__builtin_popcount(mask));
            if(len == n){
                return;
            }
            for(int i = len; i < n; ++i){
                if((mask&masks[i]) == 0 && masks[i]){
                    dfs(dfs,i+1,mask|masks[i]);
                }
            }
        };
        dfs(dfs,0,0);
        return ans;
    }
};