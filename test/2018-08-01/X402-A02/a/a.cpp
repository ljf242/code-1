#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( LL i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0,sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx(T a, T b) { return a > b ? a : b; }
template<class T> int minn(T a, T b) { return a < b ? a : b; }
template<class T> int abss(T a) { return a > 0 ? a : -a; }
#define max maxx
#define min minn
#define abs abss
const int maxn = 100010;

LL n, m, p, ans, l[maxn], a[10][10];
bool vis[10][10];

inline LL ksm(LL a, LL b, LL Mod)
{
    LL r = 1;
    while ( b )
    {
        if ( b % 2 == 1 ) 
            r *= a;
        b /= 2;
        a *= a;
        r = r % Mod;
        a = a % Mod;
    }
    return r;
}

inline void out()
{
    REP(i, 1, n) 
    {
        REP(j, 1, l[i]) printf("%lld", a[i][j]);
        printf(" ");
    }
    puts("");
}

inline void pd()
{ 
    mem(vis);
    REP(i, 1, n)
    {
        REP(j, 1, l[i]) 
        {
            if ( j != 1 && a[i][j] == a[i][j - 1] ) return ;
            vis[i][a[i][j]] = true;
        }
        if ( i != 1 )
        {
            bool flag = false;
            REP(j, 1, m)
                if ( vis[i][j] != vis[i - 1][j] ) 
                {
                    flag = true;
                    break;
                }
            if ( flag == false ) return ; 
        }
    }
    ++ ans;
    ans %= p;
}

inline void dfs(LL x, LL now)
{
    REP(i, 1, m) 
    {
        a[x][now] = i;
        if ( now == l[x] && x == n ) { pd(); continue ; }
        else if ( now == l[x] ) dfs(x + 1, 1);
        else dfs(x, now + 1);
    }
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%lld%lld%lld", &n, &m, &p);
    REP(i, 1, n)
    {
        scanf("%lld", &l[i]);
    }
    if ( n == 1 ) 
    {
        ans = m;
        ans = (ans * ksm(m - 1, l[1] - 1, p)) % p;
        printf("%lld\n", ans);
        return 0;
    }
    if ( n <= 5 && m <= 5 ) 
    {
        dfs(1, 1);
        printf("%lld\n", ans);
        return 0;
    }
    return 0;
}
