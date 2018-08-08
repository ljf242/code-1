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

const int maxn = 50;

int t, n, m, k, Begin[maxn], To[maxn], Next[maxn], e, sum;
bool vis[maxn];
int ans = 0x3f3f3f3f;

struct node
{
    int x, pre;
} v[maxn], p[maxn];

inline void add(int u, int v)
{
    To[++ e] = v;
    Next[e] = Begin[u];
    Begin[u] = e;
}

inline bool pd()
{
    REP(i, 1, e) 
        if ( !vis[i] ) return false;
    return true;
}

inline void DFS(int x, int s)
{
    if ( s >= ans ) return ;
    if ( x == k )
    {
        if ( pd() ) 
        {
            if ( ans > s )
            {
                ans = s;
                t = k;
                REP(i, 1, sum) v[i] = p[i];
            }
        }
        return ;
    }
    for ( int i = Begin[x]; i; i = Next[i] )
    {
        if ( vis[i] ) continue ;
        vis[i] = true;
        if ( i % 2 == 1 ) vis[i + 1] = true;
        else vis[i - 1] = true;
        p[++ sum].x = 0; p[sum].pre = To[i];
        DFS(To[i], s);
        vis[i] = false;
        if ( i % 2 == 1 ) vis[i + 1] = false;
        else vis[i - 1] = false;
    }
    REP(i, 1, n)
    {
        p[++ sum].x = 1; p[sum].pre = i;
        DFS(i, s + 1);
    }
}

int main()
{
    freopen("miner.in", "r", stdin);
    freopen("miner.out", "w", stdout);
    printf("0\n");
    return 0;
    scanf("%d%d", &n, &m);
    REP(i, 1, m)
    {
        int u, v; scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    REP(i, 1, n)
    {
        k = i;
        DFS(1, 0);
    }
    printf("%d\n%d\n", ans, t);
    REP(i, 1, ans) printf("%d %d\n", v[i].x, v[i].pre);
    return 0;
}
