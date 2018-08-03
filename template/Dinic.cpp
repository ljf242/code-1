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

int Begin[maxn], Head[maxn], n, m, s, t, e, dis[maxn];
bool vis[maxn];

inline void add(int u, int v, int w)
{
    Edge[e].To = v;
    Edge[e].Next = Begin[u];
    Begin[u] = e;
    Edge[e].W = w;
    ++ e;
}

inline bool BFS(int s, int t)
{
    queue<int> Q;
    Q.push(s);
    REP(i, 1, n) { Head[i] = Begin[i]; dis[i] = INF; }
    dis[s] = 0;
    while ( !Q.empty() )
    {
        int x = Q.front(); Q.pop();
        if ( x == t )  break ;
        for ( int i = Begin[x]; i; i = Edge[i].Next )
        {
            int u = Edge[i].To;
            if ( dis[u] == INF && Edge[i].W ) 
            {
                dis[u] = dis[x] + 1;
                Q.push(u);
            }
        }
    }
    if ( dis[t] == INF ) return false;
    return true;
}

inline int DFS(int now, int t, int Minflow)
{
    if ( !Minflow || now == t ) return Minflow;
    int flow = 0, f;
    for ( int i = Head[now]; i; i = Edge[i].Next )
    {
        Head[now] = i;
        if ( dis[Edge[i].To] == dis[now] + 1 && (f = DFS(Edge[i].To, t, min(Minflow, Edge[i].W))) )
        {
            flow += f;
            Minflow -= f;
            Edge[i].W -= f;
            Edge[i ^ 1].W += f;
            if ( ! Minflow ) break ;
        }
    }
    return flow;
}

inline int Dinic(int s, int t)
{
    int Maxflow = 0;
    while ( BFS(s, t) )
        Maxflow += DFS(s, t, INF);
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
