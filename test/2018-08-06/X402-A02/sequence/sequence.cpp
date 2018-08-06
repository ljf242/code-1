#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx ( T a, T b ) { return a > b ? a : b; }
template<class T> int minn ( T a, T b ) { return a < b ? a : b; }
template<class T> int abss ( T a ) { return a > 0 ? a : -a; }
#define max maxx
#define min minn
#define abs abss

const int maxn = 1000010;
const int Mod = 1e9 + 7;

int n, m, k, ans, a[maxn], dp[maxn], last[maxn];
bool vis[maxn];

inline int solve()
{
    mem(last); mem(dp);
    REP(i, 1, n + m)
    {
        if ( last[a[i]] == 0 ) dp[i] = (2 * dp[i - 1] + 1) % Mod;
        else dp[i] = (2 * dp[i - 1] - dp[last[a[i]] - 1] + Mod) % Mod;
        last[a[i]] = i; 
    }
    return dp[n + m];
}

inline void DFS(int x)
{
    if ( x == n + m + 1 )
    {
        ans = max(ans, solve());
        return ;
    }
    REP(i, 1, k)
    {
        a[x] = i;
        DFS(x + 1);
    }
}

inline void DFS1(int x)
{
    if ( x == n + m + 1 ) 
    {
        ans = max(ans, solve());
        return ;
    }
    REP(i, 1, k)
    {
        if ( !vis[a[i]] ) 
        {
            vis[a[i]] = true;
            a[x] = i;
            DFS1(x + 1);
            vis[a[i]] = false;
        }
    }
}

int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    REP(i, 1, n) scanf("%d", &a[i]);
    if ( k <= 3 ) 
    {
        DFS(n + 1); 
        printf("%d\n", ans);
        return 0;
    }
    if ( m == 0 )
    {
        printf("%d\n", solve());
        return 0;
    }
    if ( k == m )
    {
        DFS1(n + 1);
        printf("%d\n", ans);
        return 0;
    }
    return 0;
}
