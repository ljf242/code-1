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
const LL Mod = 998244353;

LL n, w[maxn], ans;

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
    scanf("%lld", &n);
    REP(i, 1, n) scanf("%lld", &w[i]);
    ans = power(1, Mod - 2);
    REP(i, 2, n) ans = (ans + (w[i] * power(w[i] + w[1], Mod - 2)) % Mod) % Mod;
    printf("%lld\n", ans);
    return 0;
}   
