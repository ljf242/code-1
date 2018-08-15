#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( LL i = (a), _end_ = (b); i <= _end_ ; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx(T a, T b) { return a > b ? a : b; }
template<class T> int minn(T a, T b) { return a < b ? a : b; }
template<class T> int abss(T a) { return a > 0 ? a : -a; }
#define max maxx
#define min minn
#define abs abss

const int maxn = 5010;
const LL Mod = 998244353;

LL n, m, k, ans, c[maxn][maxn], prime[maxn], cnt;
bool vis[maxn];

inline LL power(LL a, LL b)
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

int main()
{
    freopen("h.in", "r", stdin);
    freopen("h.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &k);
    vis[1] = true;
    REP(i, 2, n) if ( vis[i] == false ) 
    {
        prime[++ cnt] = i;
        for ( LL j = i * 2; j <= n; j += i ) vis[j] = true;
    }
    REP(i, 1, cnt ) printf("%lld ", prime[i]);
    puts("");
    REP(i, 0, n + m) c[i][0] = c[i][i] = 1; 
    REP(i, 1, n + m) 
        REP(j, 1, i - 1) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Mod;
    REP(i, 0, m)
    {
        LL ans = 0;
        for ( LL j = cnt; j >= 1; -- j )   
        {
            if ( k < prime[j] ) continue ;
            if ( k - prime[j] <= i ) ++ ans;
        }
        printf("%lld\n", (ans * power(c[i + n][k], Mod - 2)) % Mod); 
    }
    return 0;
}
