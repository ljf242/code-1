#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a )
typedef long long LL;

const int maxn = 10010;
const LL INF = 100000000000000;

int n, m, k, Begin[maxn], To[maxn], Next[maxn], e, W[maxn];
int Money[maxn], p[maxn];
LL dis[maxn], ans = INF;
bool vis[maxn];

inline void add(int u, int v, int w)
{
    To[++ e] = v;
    Next[e] = Begin[u];
    Begin[u] = e;
    W[e] = w;
}

inline void DFS(int x, int cnt)
{
    if ( x == n ) 
    {
        REP(i, 1, cnt) p[i] = Money[i]; 
        sort ( p + 1, p + cnt + 1 );
        LL sum = 0;
        REP(i, cnt - k + 1, cnt) sum += p[i];
        ans = min(ans, sum);
        return ;
    }
    for ( int i = Begin[x]; i; i = Next[i] ) 
    {
        int u = To[i];
        if ( !vis[u] ) 
        {
            vis[u] = true; Money[cnt + 1] = W[i];
            DFS(u, cnt + 1);
            vis[u] = false;
        }
    }
}

inline void SPFA()
{
    REP(i, 1, n) dis[i] = INF;
    dis[1] = 0;  
    queue<int> Q;
    Q.push(1);
    vis[1] = true;
    while ( !Q.empty() )
    {
        int u = Q.front(); Q.pop();
        for ( int i = Begin[u]; i; i = Next[i] ) 
        {
            int v = To[i];
            if ( dis[u] + W[i] < dis[v] ) 
            {
                dis[v] = dis[u] + W[i];
                if ( !vis[v] ) 
                {
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }     
        vis[u] = false;
    }
    printf("%lld\n", dis[n]);
}

int main()
{
    freopen("y.in", "r", stdin);
    freopen("y.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    if ( k == 0 ) 
    {
        printf("0\n");
        return 0;
    } 
    REP(i, 1, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    if ( k == m )
    {
        SPFA();
        return 0;
    }
    vis[1] = true;
    DFS(1, 0);
    printf("%lld\n", ans);
    return 0;
}
