#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx(T a, T b) { return a > b ? a : b; }
template<class T> int minn(T a, T b) { return a < b ? a : b; }
template<class T> int abss(T a) { return a > 0 ? a : -a ; }
#define max maxx
#define min minn
#define abs abss

const int maxn = 100010 * 2;
const int INF = 0x3f3f3f3f;

struct edge
{
    int Next, To, W;
} Edge[maxn];

int Begin[maxn], n, m, s, t, e = -1, dis[maxn];
bool vis[maxn];

inline void add(int u, int v, int w)
{
    Edge[++ e].To = v;
    Edge[e].Next = Begin[u];
    Begin[u] = e;
    Edge[e].W = w;
}

inline bool BFS(int s, int t)
{
    queue<int> Q;
    Q.push(s);
    mem(dis);
    dis[s] = 1;
    do {
        int x = Q.front(); Q.pop();
        if ( x == t )  break ;
        for ( int i = Begin[x]; i; i = Edge[i].Next )
        {
            int u = Edge[i].To;
            if ( dis[u] == 0 && Edge[i].W > 0 ) 
            {
                dis[u] = dis[x] + 1;
                Q.push(u);
            }
        }
    }while ( !Q.empty() );
    if ( dis[t] == 0 ) return false;
    return true;
}

inline int DFS(int now, int t, int flow)
{
    if ( now == t ) return flow;
    int f;
    for ( int i = Begin[now]; i; i = Edge[i].Next )
    {
        if ( dis[Edge[i].To] == dis[now] + 1 && Edge[i].W != 0 )
        {
            f = DFS(Edge[i].To, t, min(flow, Edge[i].W));
            if ( f > 0 )
            {
                Edge[i].W -= f;
                Edge[i ^ 1].W += f;
                return f;
            }
        }
    }
    return 0;
}

inline int Dinic(int s, int t)
{
    int Maxflow = 0;
    while ( BFS(s, t) )
        while ( int flow = DFS(s, t, INF) )
            Maxflow += flow;
    return Maxflow;
}

int main()
{
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d%d", &n, &m, &s, &t); 
    REP(i, 1, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, 0);
    }
    int Maxflow = Dinic(s, t);
    printf("%d\n", Maxflow);
    return 0;
}
