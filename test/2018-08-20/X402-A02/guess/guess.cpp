#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( LL i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a )
typedef long long LL;

LL a, b, c, m;

inline LL power(LL a, LL b, LL Mod)
{
    LL r = 1;
    while ( b ) 
    {
        if ( b & 1 ) r = r * a % Mod;
        a = a * a % Mod;
        b /= 2;
    }
    return r % Mod;
}

int main()
{
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout); 
    int T; scanf("%d", &T);
    while ( T -- )
    {
        scanf("%lld%lld%lld%lld", &m, &a, &b, &c);
        REP(x, 1, m)
            REP(y, 1, m)
            {
                LL sum = (power(x, a, m) + power(y, b, m)) % m;
                REP(z, 1, m)
                    if ( power(z, c, m) == sum ) 
                    {
                        printf("%lld %lld %lld\n", x, y, z);
                        goto yes;
                    }
            }
yes:;
    }
    return 0;
}
