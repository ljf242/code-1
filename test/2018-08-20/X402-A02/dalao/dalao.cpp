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

const int maxn = 4010;
const int Mod = 998244353;

int n, m, L, Begin[maxn], To[maxn], Next[maxn], e;
int v[maxn], dp[maxn][2], ans;
bool vis[maxn], flag = false;

struct node
{
    int x, sum1, sum2; // sum1 is 0, sum2 is 1
    bool Vis[maxn];
}p1, p2;

inline void add(int u, int v)
{
    To[++ e] = v;
    Next[e] = Begin[u];
    Begin[u] = e;
}

inline void DFS(int x, int sum)
{
    if ( sum > L ) return ;
    if ( x == n ) 
    {
        ++ ans;
        if ( ans > Mod ) ans -= Mod;
        return ;
    }
    for ( int i = Begin[x]; i; i = Next[i] ) 
    {
        int u = To[i];
        if ( !vis[u] ) 
        {
            vis[u] = true; 
            DFS(u, sum);
            DFS(u, sum + v[u]);
            vis[u] = false;
        }
    }
}

inline int power(int a, int b)
{
    int r = 1;
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
    freopen("dalao2.in", "r", stdin);
    freopen("dalao.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &L);
    REP(i, 1, n) scanf("%d", &v[i]);
    REP(i, 1, m)
    {
        int u, v; scanf("%d%d", &u, &v);
        add(u, v);
    }
    if ( m == n - 1 ) 
    {
        REP(i, 0, L) dp[i][1] = 1;
        REP(i, 1, n)
            for ( int j = L; j >= v[i]; -- j )
            {
                if ( dp[j][0] < dp[j - v[i]][0] + 1 ) 
                {
                    dp[j][0] = dp[j - v[i]][0] + 1;
                    dp[j][1] += dp[j - v[i]][1];
                    dp[j][1] %= Mod;
                }
                else if ( dp[j][0] == dp[j - v[i]][0] + 1 )
                {
                    dp[j][1] += dp[j - v[i]][1];
                    dp[j][1] %= Mod;
                }
            }        
        printf("%d\n", dp[L][1] % Mod);
    }
    else if ( n <= 18 ) 
    {
        vis[1] = true;
        DFS(1, 0); DFS(1, v[1]);
        printf("%d\n", ans % Mod);
    }
    else if ( L == 1 )
    {
        queue<node> Q;
        p1.x = 1; p1.sum1 = v[1] == 0 ? 1 : 0;
        p1.sum2 = v[1] == 1 ? 1 : 0;
        mem(p1.Vis); p1.Vis[1] = true;
        Q.push(p1);
        while ( !Q.empty() )
        {
            p1 = Q.front(); Q.pop();
            if ( p1.x == n )
            {
                ans = (ans + (power(2, p1.sum1) * (p1.sum2 + 1) % Mod)) % Mod;
                continue ;
            } 
            for ( int i = Begin[p1.x]; i; i = Next[i] ) 
            {
                int u = To[i];  
                if ( !p1.Vis[u] ) 
                {
                    p2 = p1;
                    p2.Vis[u] = true; p2.x = u;
                    p2.sum1 += v[u] == 0 ? 1 : 0;
                    p2.sum2 += v[u] == 1 ? 1 : 0;
                    Q.push(p2);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
