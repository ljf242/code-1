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

const int Mod = 998244353;

int n, cnt, dp[1010];
int ans[1010];

int main()
{
    freopen("bag.in", "r", stdin);
    freopen("bag.out", "w", stdout);
    scanf("%d", &n);
    dp[0] = 1;
    REP(i, 1, n)
        REP(j, 1, i)
            for ( int k = n; k >= 0; k -- )
                if ( dp[k] && k + i <= n ) 
                    dp[k + i] ++ ;
    printf("%d\n", dp[n]);
    return 0;
}
