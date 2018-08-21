#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a )
typedef long long LL;

const int maxn = 210;

struct node
{
    int x, y;
} a[maxn];

int n, p[100010], ans;

inline void DFS(int x, int sum)
{
    if ( x == n + 1 ) 
    {
        ans = max(ans, sum);
        return ;
    }
    if ( p[a[x].x] == 0 ) 
    {
        p[a[x].x] = 1; DFS(x + 1, sum + a[x].y);
        p[a[x].x] = 0;
    }
    if ( p[a[x].y] == 0 )
    {
        p[a[x].y] = 1; DFS(x + 1, sum + a[x].x);
        p[a[x].y] = 0;
    }
}

int main()
{
    freopen("s.in", "r", stdin);
    freopen("s.out", "w", stdout);
    scanf("%d", &n);
    REP(i, 1, n) scanf("%d%d", &a[i].x, &a[i].y);
    DFS(1, 0);
    printf("%d\n", ans);
    return 0;
}
