/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution1{
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> vis;
        unordered_set<string> words(wordList.begin(),wordList.end());

        queue<string> q;q.emplace(beginWord);
        vis[beginWord] = 1;
        while(!q.empty()){
            auto cur = q.front();q.pop();
            auto step = vis[cur];
            for(auto& c : cur){
                for(int i = 0; i < 26; ++i){
                    auto tmp = c;
                    c = 'a' + i;
                    if(!vis[cur] && words.count(cur)){
                        if(cur == endWord){
                            return step + 1;
                        }
                        q.emplace(cur);
                        vis[cur] = step + 1;
                    }
                    c = tmp;
                }
            }
        }
        return 0;
    }
};
// @lc code=start
class Solution2 {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> vis1,vis2;
        unordered_set<string> words(wordList.begin(),wordList.end());

        queue<string> q1,q2;
        q1.emplace(beginWord);q2.emplace(endWord);
        vis1[beginWord] = 1;vis2[endWord] = 1;
        while(!q1.empty() && !q2.empty()){
            if(q1.size() < q2.size()){
                swap(q1,q2);
                swap(vis1,vis2);
            }
            auto cur = q1.front();q1.pop();
            auto step = vis1[cur];
            for(auto& c : cur){
                for(int i = 0; i < 26; ++i){
                    auto tmp = c;
                    c = 'a' + i;
                    if(words.count(cur)){
                        if(vis1[cur]){
                            c = tmp;
                            continue;
                        } 
                        else if(vis2[cur]){
                            return step + vis2[cur];
                        }
                        if(cur == endWord){
                            return step + 1;
                        }
                        q1.emplace(cur);
                        vis1[cur] = step + 1;
                    }
                    c = tmp;
                }
            }
        }
        return 0;
    }
};
// @lc code=end

