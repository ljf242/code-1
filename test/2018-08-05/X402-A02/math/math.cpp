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
const int Mod = 1e9 + 7;

LL n, m, p1[maxn], p2[maxn], a[maxn], ans, b[maxn];

inline LL js()
{
    p1[n] = a[n];
    REP(i, 1, n - 1)
    {
        p1[i] = a[i]; p2[i] = b[i];
        if ( p2[i] != 3 ) continue ;
        p1[i + 1] = p1[i] * p1[i + 1] % Mod; p1[i] = 0;
        p2[i] = p2[i - 1];
    }
    LL sum = p1[1];
    REP(i, 1, n - 1)
    {
        if ( p2[i] == 1 ) sum += p1[i + 1];
        else sum -= p1[i + 1];
    }
    return sum;
}

inline void DFS(LL x)
{
    if ( x == n ) 
    {
        ans += js();
        return ;
    }
    REP(i, 1, 3)
    {
        b[x] = i;
        DFS(x + 1);
    }
}

int main()
{
    freopen("math.in", "r", stdin);
    freopen("math.out", "w", stdout);
    p2[0] = 1;
    scanf("%lld%lld", &n, &m);
    REP(i, 1, n) scanf("%lld", &a[i]);
    REP(i, 1, m)
    {
        ans = 0;
        LL x, y;
        scanf("%lld%lld", &x, &y);
        a[x] = y;
        DFS(1);
        printf("%lld\n", ans);
    }
    return 0;
}

