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

const int maxn = 1010;
const int Mod = 998244353;

int Begin[maxn], To[maxn], Next[maxn], e;
int n, m, ans, a[maxn], sum, G[maxn], cnt;
bool vis[20], flag;

inline void add(int u, int v)
{
    To[++ e] = v;
    Next[e] = Begin[u];
    Begin[u] = e;
}

inline bool PD()
{
    REP(i, 1, G[0])
        if ( vis[i] == false ) return false;
    return true;
}

inline void dfs(int x, int sum)
{
    //printf("%d %d %d\n", x, sum, cnt);
    //REP(i, 1, n) printf("%d", vis[i]);
    //puts("");
    if ( flag == true ) return ;
    if ( cnt > 100 ) { flag = true; return ; }
    if ( sum > 10000 ) return ;
    if ( x == 1 && PD() ) 
    {
        ++ cnt;
        mem(vis);
    }
    vis[x] = true;
    for ( int i = Begin[x]; i; i = Next[i] ) 
    {
        int u = To[i];
        dfs(u, sum + 1);
        vis[u] = false;
    } 
}

inline bool pd()
{
    vector<int> p[maxn];
    REP(i, 1, n)
    {
        p[a[i]].push_back(i);
    }
    REP(i, 1, sum) 
        if ( p[i].size() == 1 ) return false;
    REP(i, 1, sum)
    {
        mem(vis);
        cnt = 0;
        REP(j, 0, p[i].size() - 1)
            G[j + 1] = p[i][j];
        G[0] = p[i].size();
        flag = false;
        dfs(1, 0);
        if ( flag == true ) continue ;
        else return false;
    } 
    return true;
}

inline void DFS(int x)
{
    if ( x == n + 1 ) 
    {
        if ( pd() ) ++ ans;
        return ;
    }
    REP(i, 1, sum)
    {
        a[x] = i;
        DFS(x + 1);
    }
    ++ sum;
    a[x] = sum;
    DFS(x + 1);
}

inline int C(int a, int b)
{
    int sum = 1;
    REP(i, b - a + 1, b)
        sum *= i;
    REP(i, 1, a)
        sum /= i;
    return sum;
}

int main()
{
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    scanf("%d%d", &n, &m);
    if ( m == n * (n - 1) )
    {
        ans = 1;
        REP(i, 2, n - 2) ans += C(i, n) / 2;
        printf("%d\n", ans);
        return 0;
    }
    REP(i, 1, m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    DFS(1);
    printf("%d\n", ans);
    return 0;
}
