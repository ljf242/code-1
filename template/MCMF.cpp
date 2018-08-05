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
    int From, Next, To, W, dis;
} Edge[maxn];

int Begin[maxn], n, m, s, t, e = -1, dis[maxn], a[maxn], pre[maxn];
bool vis[maxn];

inline void add(int u, int v, int w, int dis)
{
    Edge[++ e].To = v;
    Edge[e].From = u;
    Edge[e].Next = Begin[u];
    Begin[u] = e;
    Edge[e].W = w;
    Edge[e].dis = dis;
}

inline bool BFS(int s, int t)
{
    REP(i, 0, n) dis[i] = INF;
    queue<int> Q;
    Q.push(s);
    mem(vis);
    dis[s] = pre[s] = 0; a[s] = INF;
    vis[s] = true;
    while ( !Q.empty() ) 
    {
        int x = Q.front(); Q.pop();
        vis[x] = false;
        for ( int i = Begin[x]; i; i = Edge[i].Next )
        {
            int u = Edge[i].To;
            if ( dis[u] > dis[x] + Edge[i].dis && Edge[i].W > 0 ) 
            {
                dis[u] = dis[x] + Edge[i].dis;
                pre[u] = i;
                a[u] = min ( a[x], Edge[i].W );
                if ( vis[u] == false ) 
                {
                    vis[u] = true;
                    Q.push(u);
                }
            }
        }
    }
    if ( dis[t] == INF ) return false;
    return true;
}

inline bool SPFA(int s, int t, int &flow, int &cost)
{
    if ( BFS(s, t) == false ) return false;
    cost += a[t] * dis[t];
    flow += a[t];
    int u = t;
    while ( u != s ) 
    {
        Edge[pre[u]].W -= a[t];
        Edge[pre[u] ^ 1].W += a[t];
        u = Edge[pre[u]].From;
    }
    return true;
}

inline void MCMF(int s, int t)
{
    int cost = 0, flow = 0;
    while ( SPFA(s, t, flow, cost) ) ;
    printf("%d %d\n", flow, cost);
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
        int u, v, w, c;
        scanf("%d%d%d%d", &u, &v, &w, &c);
        add(u, v, w, c);
        add(v, u, 0, -c);
    }
    MCMF(s, t);
    return 0;
}
