#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a )
typedef long long LL;
template<class T> int maxx(T a, T b) { return a > b ? a : b; }
template<class T> int minn(T a, T b) { return a < b ? a : b; }
template<class T> int abss(T a) { return a > 0 ? a : -a; }
#define min minn
#define abs abss
#define max maxx

const int maxn = 30;
const int Mod = 998244353;

LL n, w[maxn], S, ans;
bool vis[maxn];

inline LL power(LL a, LL b, LL Mod)
{
    LL r = 1;
    while ( b ) 
    {
        if ( b & 1 ) r = r * a % Mod;
        b /= 2; a = a * a % Mod;
    }
    return r;
}

inline void DFS(LL x, LL now, LL sum)
{
    if ( now == 1 ) 
    {
        ans = (ans + x * sum) % Mod;
        return ;
    }
    S -= w[now];
    REP(i, 1, n)
    {
        if ( vis[i] ) continue ;
        vis[i] = true;
        DFS(x + 1, i, sum * w[i] * power(S, Mod - 2, Mod) % Mod);        
        vis[i] = false;
    }   
    S += w[now];
}

int main()
{
    freopen("hunter.in", "r", stdin);
    freopen("hunter.out", "w", stdout);
    scanf("%lld", &n);
    REP(i, 1, n) { scanf("%lld", &w[i]); S += w[i]; }
    int ans1 = 0, ans2 = 0;
    if ( n == 1 ) { printf("1\n"); return 0; }
    REP(i, 1, n)
    {
        vis[i] = true;
        DFS(1, i, w[i] * power(S, Mod - 2, Mod) % Mod); 
        vis[i] = false;
    }
    printf("%lld\n", ans);
    return 0;
}
