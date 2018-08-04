#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( register int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx(T a, T b) { return a > b ? a : b; }
template<class T> int minn(T a, T b) { return a < b ? a : b; }
template<class T> int abss(T a) { return a > 0 ? a : -a; }
#define min minn
#define max maxx
#define abs abss

const int maxn = 100100;
const LL INF = 100000000000000;

int Begin[maxn], To[maxn], Next[maxn], e;
LL dis[maxn], W[maxn];
int n, m, q, Q[maxn];
bool vis[maxn];

inline void add(int u, int v, LL w)
{
    To[++ e] = v;
    Next[e] = Begin[u];
    Begin[u] = e;
    W[e] = w;
}

inline void SPFA(int s, int t)
{
    REP(i, 1, n) dis[i] = INF;
    mem(vis);
    dis[s] = 0; vis[s] = true;
    LL ans = INF;
    deque<int> Q;
    Q.push_back(s);
    while ( !Q.empty() )
    {
        int u = Q.front(); Q.pop_front();
        if ( dis[u] >= ans ) { vis[u] = false; continue ; }
        if ( u == t && ans > dis[u] ) ans = dis[u];
        vis[u] = false;
        for ( int i = Begin[u]; i; i = Next[i] ) 
        {
            int v = To[i];
            if ( dis[v] > dis[u] + W[i] ) 
            {
                dis[v] = dis[u] + W[i];
                if ( vis[v] == false )
                {
                    vis[v] = true;
                    if ( Q.empty() || dis[v] > dis[Q.front()] ) 
                        Q.push_back(v);
                    else Q.push_front(v);
                }
            }
        }
    }
}

int main()
{
    freopen("fly.in", "r", stdin);
    freopen("fly.out", "w", stdout);
    scanf("%d%d", &n, &m);    
    REP(i, 1, n)  
    {
        LL x;
        scanf("%lld", &x);
        if ( i == n ) 
        {
            add(n, 1, x);
            add(1, n, x);
        }
        else 
        {
            add(i, i + 1, x);
            add(i + 1, i, x);
        }
    }
    REP(i, 1, m)
    {
        int u, v;
        LL w;
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    scanf("%d", &q);
    while ( q -- )
    {
        int u, v;
        scanf("%d%d", &u, &v);
        SPFA(u, v);
        printf("%lld\n", dis[v]);
    }
    return 0;
}
