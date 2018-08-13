#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a )
typedef long long LL;
template<class T> LL maxx(T a, T b) { return a > b ? a : b; }
template<class T> LL minn(T a, T b) { return a < b ? a : b; }
template<class T> LL abss(T a) { return a > 0 ? a : -a; }
#define max maxx
#define abs abss
#define min minn

const int maxn = 100010;

LL T, n, m;
struct node
{
    LL x, k, a, b, x1, x2;
    bool flag;
} a[maxn], b[maxn], p[maxn];

inline LL cmp(node a, node b)
{
    return a.x < b.x ? 1 : 0;
}

int main()
{
    freopen("d.in", "r", stdin);
    freopen("d.out", "w", stdout);
    scanf("%lld", &T);
    while ( T -- )
    {
        scanf("%lld%lld", &n, &m);
        REP(i, 1, n)
        {
            scanf("%lld%lld", &a[i].x, &b[i].x);
            a[i].k = b[i].k = i;
            a[i].flag = b[i].flag = true;
        }
        if ( n == m + 1 )
        {
            LL ans = 0;
            REP(i, 1, n) ans = max(ans, a[i].x * b[i].x);
            printf("%lld\n", ans);
            continue ;
        }
        sort ( a + 1, a + n + 1, cmp );
        sort ( b + 1, b + n + 1, cmp ); 
        REP(i, 1, n) 
        {
            p[a[i].k].a = a[i].x; p[a[i].k].x1 = i;
            p[b[i].k].b = b[i].x; p[b[i].k].x2 = i;
        }
//        REP(i, 1, n) printf("%d %d\n", a[i].k, a[i].x);
//        REP(i, 1, n) printf("%d %d\n", b[i].k, b[i].x);
        LL x1 = 1, y1 = 1, Minx = a[1].x, Miny = b[1].x;
        REP(i, 1, m)
        {
//            REP(j, 1, n) cout << a[j].flag << " ";
//            cout << endl;
//            REP(j, 1, n) cout << b[j].flag << " ";
//            cout << endl;
            if ( a[x1].k == b[y1].k ) 
            {
                a[x1].flag = b[y1].flag = false;
                Minx = a[++ x1].x; Miny = b[++ y1].x;
                continue ;
            }
            while ( a[x1].flag == false ) Minx = a[++ x1].x;
            while ( b[y1].flag == false ) Miny = b[++ y1].x;
            while ( a[x1 + 1].flag == false ) ++ x1;
            while ( b[y1 + 1].flag == false ) ++ y1;
            LL Sum1 = a[x1 + 1].x * Miny;
            LL Sum2 = Minx * b[y1 + 1].x; 
//            printf("%lld %lld %lld %lld ", a[x1].k, b[y1].k, Minx, Miny);
//            printf("%lld %lld %lld %lld\n", a[x1 + 1].x, b[y1 + 1].x, Sum1, Sum2);
            if ( Sum1 > Sum2 ) 
            { 
                a[x1].flag = false; b[p[a[x1].k].x2].flag = false;
                Minx = a[++ x1].x;
            }
            else 
            {
                b[y1].flag = false; a[p[b[y1].k].x1].flag = false;
                Miny = b[++ y1].x;
            }
//            while ( a[x1].flag == false ) Minx = a[++ x1].x;
//            while ( b[y1].flag == false ) Miny = b[++ y1].x;
        }
        if ( a[x1].k == b[y1].k ) { Minx = a[++ x1].x; Miny = b[++ y1].x; }
        printf("%lld\n", Minx * Miny);
    }
    return 0;
}

