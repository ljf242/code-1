#include<bits/stdc++.h>
#include<time.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define str(a) strlen ( a ) 
#define mem(a) memset ( (a), 0, sizeof ( a ) )
typedef long long LL;
template<class T> inline int maxx(T a, T b) { return a > b ? a : b; }
template<class T> inline int minn(T a, T b) { return a < b ? a : b; }
template<class T> inline int abss(T a) { return a < 0 ? -a : a; }
#define max maxx
#define min minn
#define abs abss

int main()
{
    freopen("game.in", "w", stdout);
    int n = 8, m = 100000;
    printf("%d %d\n", n, m);
    srand(time(0));
    int u1 = rand() % n + 1;
    int v1 = rand() % n + 1;
    int u2 = rand() % n + 1;
    int v2 = rand() % n + 1;
    while ( u1 == v1 && u2 == v2 ) 
    {
        u2 = rand() % n + 1;
        v2 = rand() % n + 1;
    }
    int w1 = (rand() % 2 + 1) * 2;
    int w2 = (rand() % 2 + 1) * 2;
    printf("%d %d %d %d %d %d\n", u1, v1, w1, u2, v2, w2);
    REP(i, 1, m)
    {
        int x = rand() % 3;
        int cnt = rand() % 2147483648 + 1;
        int v = (rand() % 2 + 1) * 2;
        printf("%d %d %d\n", x, cnt, v);
    }
    return 0;
}
