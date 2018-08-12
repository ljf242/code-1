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
#define abs abss
#define min minn

const int maxn = 100010;
const int Mod = 1e9 + 7;

int a[21][maxn], n, m, ans;
int p[21][21][21][21];

inline int gcd(int x, int y)
{
    return x % y == 0 ? y : gcd(y, x % y);
}

inline void DFS(int x, int sum)
{
    if ( x == n ) { ans = (ans + sum) % Mod;  return ; }
    if ( x > 1 ) 
    {
        ans = (ans + sum) % Mod;
    }
    REP(i, 1, m)
    {
        int t = sum;
        if ( sum == 0 ) t = a[x + 1][i];
        else t = gcd(sum, a[x + 1][i]);
        DFS(x + 1, t);
    }
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, 1, n) REP(j, 1, m) { scanf("%d", &a[i][j]); ans = (ans + a[i][j]) % Mod; }
    if ( n == 1 ) 
    {
        printf("%d\n", ans);
        return 0;
    }
    DFS(0, 0);
    printf("%d\n", ans);
    return 0;
}
