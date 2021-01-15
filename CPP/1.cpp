/* ***********************************************
Author        :kuangbin
Created Time  :2014-2-1 0:46:43
File Name     :E:\2014ACM\SGU\SGU101.cpp
************************************************ */

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

struct Edge
{
    int to,next;
    int index;
    int dir;
    bool flag;
}edge[220];
int head[30],tot;
void init()
{
    memset(head,-1,sizeof(head));
    tot = 0;
}
void addedge(int u,int v,int index)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].index = index;
    edge[tot].dir = 0;
    edge[tot].flag = false;
    head[u] = tot++;
    edge[tot].to = u;
    edge[tot].next = head[v];
    edge[tot].index = index;
    edge[tot].dir = 1;
    edge[tot].flag = false;
    head[v] = tot++;
}
int du[30];
int F[30];
int find(int x)
{
    if(F[x] == -1)return x;
    else return F[x] = find(F[x]);
}
void bing(int u,int v)
{
    int t1 = find(u);
    int t2 = find(v);
    if(t1 != t2)
        F[t1] = t2;
}
vector<int>ans;
void dfs(int u)
{
    for(int i = head[u]; i != -1;i = edge[i].next)
        if(!edge[i].flag )
        {
            edge[i].flag = true;
            edge[i^1].flag = true;
            dfs(edge[i].to);
            ans.push_back(i);
        }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n) == 1)
    {
        init();
        int u,v;
        memset(du,0,sizeof(du));
        memset(F,-1,sizeof(F));
        for(int i = 1;i <= n;i++)
        {
            scanf("%d%d",&u,&v);
            addedge(u,v,i);
            du[u]++;
            du[v]++;
            bing(u,v);
        }
        int s = -1;
        int cnt = 0;
        for(int i = 0;i <= 6;i++)
        {
            if(du[i]&1) cnt++;
            if(du[i] > 0 && s == -1)
                s = i;
        }
        bool ff = true;
        if(cnt != 0 && cnt != 2)
        {
            printf("No solution\n");
            continue;
        }
        for(int i = 0; i <= 6;i++)
            if(du[i] > 0 && find(i) != find(s))
                ff = false;
        if(!ff)
        {
            printf("No solution\n");
            continue;
        }
        ans.clear();
        if(cnt == 0)dfs(s);
        else
        {
            for(int i = 0;i <= 6;i++)
                if(du[i] & 1)
                {
                    dfs(i);
                    break;
                }
        }
        for(int i = 0;i < ans.size();i++)
        {
            printf("%d ",edge[ans[i]].index);
            if(edge[ans[i]].dir == 0)printf("-\n");
            else printf("+\n");
        }
    }
    return 0;
}