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

const int maxn = 300;

int n, m, Begin[maxn], To[maxn], Next[maxn], W[maxn], e;
int sum, ans, Ans = 2147483647;
int vis[maxn];

inline void add(int u, int v, int w)
{
    To[++ e] = v;
    Next[e] = Begin[u];
    Begin[u] = e;
    W[e] = w;
}

inline void DFS(int x, int now, int S, int Min)
{
    if ( now == 1 && vis[now] ) 
    {
        if ( S > ans && vis[n] == true ) 
        {
            ans = S;
            Ans = min(Ans, Min);
        }
        return ;
    }
    vis[now] = true;
    for ( int i = Begin[now]; i; i = Next[i]  )
    {
        if ( !vis[To[i]] || To[i] == 1 ) 
        {
            vis[To[i]] = true;
            DFS(x + 1, To[i], S + W[i], min(Min, W[i]));
            vis[To[i]] = false;
        }
    }
}

int main()
{
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    scanf("%d%d", &n, &m); 
    REP(i, 1, m)
    {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
        sum += w;
    }
    DFS(1, 1, 0, 2147483647);
    printf("%d\n", sum - ans + Ans);
    return 0;
}
