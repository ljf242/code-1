#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx ( T a, T b ) { return a > b ? a : b; }
template<class T> int minn ( T a, T b ) { return a < b ? a : b; }
template<class T> int abss ( T a ) { return a > 0 ? a : -a; }
#define abs abss
#define min minn
#define abs abss

const int maxn = 10000010;

int L, R, K, prime[maxn], cnt;
bool Mark[maxn];
LL ans;

int main()
{
    freopen("prime.in", "r", stdin);
    freopen("prime.out", "w", stdout);
    scanf("%d%d%d", &L, &R, &K);
    REP(i, 2, K)
    {
        if ( !Mark[i] ) prime[++ cnt] = i;
        for ( int j = 1; j <= cnt && prime[j] * i <= K; ++ j )
        {
            Mark[i * prime[j]] = true;
            if ( i % prime[j] == 0 ) break ;
        }
    }
    if ( K == 1 ) 
    {
        REP(i, L, R) ans ^= i;
        printf("%lld\n", ans);
        return 0;
    }
    REP(i, L, R)
    {
        bool flag = true;
        REP(j, 1, cnt)
        {
            if ( prime[j] >= i ) continue ;
            if ( i % prime[j] == 0 ) 
            {
                flag = false;
                break ;
            }
        }
        if ( flag == true ) ans ^= i;
    }
    printf("%lld\n", ans);
    return 0;
}
