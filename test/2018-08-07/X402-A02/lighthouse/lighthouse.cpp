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

const int maxn = 60;
const int Mod = 1e9 + 7;

int n, m, a[maxn][maxn], ans, p[maxn], sum;
bool vis[maxn];

inline void DFS(int x)
{
    if ( x == n + 1 ) 
    {
        if ( a[p[1]][p[n]] == 0 ) 
        {++ sum;
//        REP(i, 1, n) printf("%d ", p[i]); puts("");
//        REP(i, 1, n) printf("%d", vis[i]); puts("");
        if ( sum == n * 2 ) { sum = 0; ++ ans; }
        if ( ans > Mod ) ans -= Mod;
        }
        return ;
    }
    REP(i, 1, n)
        if ( !vis[i] )
        {
            if ( (x != 1 && !a[p[x - 1]][i]) || x == 1 )
            {
                vis[i] = true;
                p[x] = i;
                DFS(x + 1);
                vis[i] = false;
            }
        }
}

int main()
{
    freopen("lighthouse.in", "r", stdin);
    freopen("lighthouse.out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, 1, m)
    {
        int u, v; scanf("%d%d", &u, &v);
        a[u][v] = a[v][u] = 1;
    }    
    if ( m == 0 )
    {
        LL ans = 1;
        REP(i, 3, n - 1) ans = ans * i % Mod; 
        printf("%lld\n", ans);
        return 0;
    }
    if ( m == 1 ) 
    {
        LL ans = 1, sum = 1;
        REP(i, 3, n - 1) ans = ans * i % Mod;
        REP(i, 2, n - 2) sum = sum * i % Mod;
        ans = (ans + Mod - sum) % Mod;
        printf("%lld\n", ans);
        return 0;
    }
    DFS(1);
    printf("%d\n", ans);
    return 0;
}
