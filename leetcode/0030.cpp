class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int slen = s.size(), wnum = words.size();
        vector<int> ans;
        if (!slen || !wnum) return ans;
        int wlen = words[0].size();
        if (slen < wnum * wlen) return ans;

        unordered_map<string, int> wmap, smap;
        for (auto i : words) wmap[i]++;

        for (int i = 0; i < wlen; i++) {
            smap.clear();
            int count = 0;
            for (int l = i, r = i; l <= slen - wlen * wnum && r <= slen - wlen;
                 r += wlen) {
                string temp = s.substr(r, wlen);
                if (wmap[temp]) {
                    smap[temp]++;
                    count++;
                    while (wmap[temp] < smap[temp]) {
                        smap[s.substr(l, wlen)]--;
                        l += wlen;
                        count--;
                    }
                    if (count == wnum) {
                        ans.push_back(l);
                        smap[s.substr(l, wlen)]--;
                        l += wlen;
                        count--;
                    }
                } else {
                    count = 0;
                    smap.clear();
                    l = r + wlen;
                }
            }
        }
        return ans;
    }
};