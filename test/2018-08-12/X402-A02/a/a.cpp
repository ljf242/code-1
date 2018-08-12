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

LL n, m, a[31][50010], c[31][50010], result[50010], l, r;
LL Sum[50010], vis[50010], p[50010];
LL ans;

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    REP(i, 1, n) 
    {
        getchar();
        REP(j, 1, m) { char c1 = getchar(); a[i][j] = c1 - '0'; } 
    }
    scanf("%lld%lld", &l, &r);
    REP(i, 1, n) REP(j, 1, m) c[i][j] = c[i - 1][j] + a[i][j];
    REP(i, 1, n)
        REP(j, i, n)
        {
            LL sum = 0;
            mem(vis);
            REP(k, 1, m) 
            { 
                result[k] = c[j][k] - c[i - 1][k]; 
                Sum[k] = Sum[k - 1] + result[k];
       //         vis[Sum[k]] ++;
            }
       //     p[0] = vis[0];
       //     REP(k, 1, m) p[k] = p[k - 1] + vis[k];
            REP(k, 1, m)
            {
                sum += result[k];
       //         if ( sum < l ) continue ;
       //         if ( sum <= r ) ans += abs(p[sum - l] + 1);
       //         else ans += p[sum - l] - p[sum - r];
                if ( l <= sum && sum <= r ) ++ ans; 
                REP(t, 1, k - 1)
                    if ( l <= (sum - Sum[t]) && (sum - Sum[t]) <= r ) ++ ans;
            }
        }
    printf("%lld\n", ans);
    return 0;
}
/*
10111
2 3
1 1 2 3 4
2 1 1 1 0
2 3 4 5 5
*/
