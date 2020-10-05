/*
Date:2020/10/05
Author:WenDavid552
Description:The most basic Dijkstra.
First input n = numbers of nodes, m = numbers of edges.
Then input m lines like: u v l , implies a unconditional edge between (u,v) and its length is l.
Finally input begin_node = where we move from.
*/
#include <cstdio>
#include <queue>
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int maxn = 1e5+10;
const int maxm = 2e5+10;
const int _INF = 2e9+10;    //The length of edge will not above 1e9. 1e9+1e9<2e9+10

inline int
readint()
{
    int x=0;char c=getchar();
    for(;c<'0'||c>'9';c=getchar());
    for(;c>='0'&&c<='9';c=getchar())x=x*10+c-'0';
    return x;
}
struct node{
    int p,nxt;
    int l;
}e[maxm*2]; int ed=0;
int g[maxn];

inline void
add_edge(int u,int v,int l)
{
    e[ed].nxt = g[u];
    e[ed].p = v;
    e[ed].l = l;
    g[u] = ed++;
}

int n,m;
int dis[maxn];
priority_queue<int,vector<int>,greater<int> > Q;
void
Dijkstra(int begin_node)
{
    fo(i,1,n) dis[i] = INF;
    dis[begin_node] = 0;
    Q.push(begin_node);
    while(!Q.empty()){
        int u = Q.top();
        for(int x=g[u];x;x=e[x].nxt){
            int v = e[x].p;
            if (dis[u] + e[x].l < dis[v]){
                dis[v] = dis[u] + e[x].l;
                Q.push(v);
            }
        }
        Q.pop();
    }
}

int
main()
{
    readint(n);readint(m);
    fo(i,1,m){
        int u,v,l;
        readint(u);readint(v);readint(l);
        addedge(u,v,l);
        addedge(v,u,l);
    }
    
    int begin_node; readint(begin_node);
    Dijkstra(begin_node);
    /*
    fo(i,1,n) printf("%d ",dis[i]);
    */
    //Output in format
    fo(i,1,n){
        if(dis[i]!=INF)
            printf("Node %d:\t%d",i,dis[i]);
        else
            printf("Node %d:Unable to reach",i);
    }
    return 0;
}
