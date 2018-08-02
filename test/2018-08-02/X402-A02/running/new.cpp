#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx(T a, T b) { return a > b ? a : b; }
template<class T> int minn(T a, T b) { return a < b ? a : b; }
template<class T> int abss(T a) { return a > 0 ? a : -a; }
#define max maxx
#define min minn
#define abs abss
const int maxn = 100010;
const int Mod = 998244353;

int n, e, Begin[maxn * 2], Next[maxn * 2], To[maxn * 2], W[maxn];
int p, q, dis[maxn], fa[maxn], dp[maxn][110], Maxdis;
bool vis[maxn];

inline void add(int u, int v)
{
    To[++ e] = v;
    Next[e] = Begin[u];
    Begin[u] = e;
}

inline LL power(LL a, LL b, LL Mod)
{
    LL r = 1;
    while ( b )
    {
        if ( b & 1 ) r = r * a % Mod;
        a = a * a % Mod;
        b /= 2;
    }
    return r;
}

inline void Build(int x, int last)
{
    vis[x] = true;
    dis[x] = dis[last] + 1;
    Maxdis = max(Maxdis, dis[x]);
    fa[x] = last;
    for ( int i = Begin[x]; i; i = Next[i] ) if ( vis[To[i]] == false ) Build(To[i], x); 
}

inline void dfs(int x)
{
    REP(i, 1, Maxdis) dp[x][i] = dp[fa[x]][i - 1];
    dp[x][0] = 1; 
    vis[x] = true;
    for ( int i = Begin[x]; i; i = Next[i] ) 
    {
        if ( vis[To[i]] == true ) continue ;
        dfs(To[i]);
        REP(j, 1, Maxdis)
        {
            dp[x][j] += dp[To[i]][j - 1];
        } 
    }
}

int main()
{
    freopen("running.in", "r", stdin);
    freopen("running.out", "w", stdout)
    scanf("%d", &n);
    REP(i, 1, n - 1)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    REP(i, 1, n) scanf("%d", &W[i]); 
    Build(1, 0);
    mem(vis);
    dfs(1); 
    q = n * n;
    REP(i, 1, n) p += dp[i][W[i]];
    REP(i, 1, n)
        REP(j, 0, Maxdis)
            printf("%d %d %d\n", i, j, dp[i][j]);
    printf("%d %d\n", p, q);
    printf("%lld\n", p * power(q, Mod - 2, Mod) % Mod);
    return 0;   
}
