#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(a) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx ( T a, T b ) { return a > b ? a : b; }
template<class T> int minn ( T a, T b ) { return a < b ? a : b; }
template<class T> int abss ( T a ) { return a > 0 ? a : -a; }
#define max maxx
#define min minn
#define abs abss

const int Mod = 998244353;

int n, ans, vis[110];

inline void DFS(int sum, int x)
{
    if ( sum > n ) return ;
    if ( x > n ) return ;
    if ( sum == n ) 
    {
        ++ ans;
        return ;
    }
    if ( vis[x] == x ) DFS(sum, x + 1);
    else
    {
        vis[x] ++;
        DFS(sum + x, x);
        vis[x] --;
        DFS(sum, x + 1);
    }
}

int main()
{
    freopen("bag.in", "r", stdin);
    freopen("bag.out", "w", stdout);
    scanf("%d", &n);
    DFS(0, 1);
    printf("%d\n", ans);
    return 0;
}
