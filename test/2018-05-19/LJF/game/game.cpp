#include<bits/stdc++.h>

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

const int maxn = 10;

int n, m, a[maxn][maxn], W, ans;
bool vis[maxn][maxn];

void finish(int x)
{
    printf("%d\n%d\n", x, ans);
    exit(0);
}

void Move(int x, int u)
{
    ans = W;
    /*
    4020
    2000
    0000
    0000
    */
    // up; 0;
    if ( x == 0 )
    {
        bool flag = false;
        REP(i, 1, n)
            REP(j, 1, n)
                if ( a[i][j] != 0 )
                {
                    while ( a[i - 1][j] == 0 && i > 1 ) 
                    {
                        swap(a[i - 1][j], a[i][j]);
                        -- i;
                        flag = true;
                    }
                }
        mem(vis);
        REP(i, 2, n)
        {
            REP(j, 1, n)
            {
                if ( a[i - 1][j] != 0 && a[i - 1][j] == a[i][j] && vis[i][j] == false && vis[i - 1][j] == false ) 
                {
                    vis[i - 1][j] = true;
                    a[i - 1][j] += a[i][j];
                    a[i][j] = 0;
                    flag = true;
                    W += a[i - 1][j];
                }
            }
        }
        REP(i, 1, n)
            REP(j, 1, n)
                if ( a[i][j] != 0 )
                {
                    while ( a[i - 1][j] == 0 && i > 1 )
                    {
                        swap(a[i - 1][j], a[i][j]);
                        -- i;
                        flag = true;
                    }
                }
        if ( flag == false ) finish(u - 1);
    }
    // down; 1;
    else if ( x == 1 )
    {
        bool flag = false;
        for ( int i = n; i >= 1; -- i)
            REP(j, 1, n)
                if ( a[i][j] != 0 )
                {
                    while ( a[i + 1][j] == 0 && i < n ) 
                    {
                        swap(a[i + 1][j], a[i][j]);
                        ++ i;
                        flag = true;
                    }
                }
        mem(vis);
        for ( int i = n - 1; i >= 1; -- i)
        {
            REP(j, 1, n)
            {
                if ( a[i + 1][j] != 0 && a[i + 1][j] == a[i][j] && vis[i][j] == false && vis[i + 1][j] == false ) 
                {
                    vis[i + 1][j] = true;
                    a[i + 1][j] += a[i][j];
                    a[i][j] = 0;
                    flag = true;
                    W += a[i + 1][j];
                }
            }
        }
        for ( int i = n; i >= 1; -- i)
            REP(j, 1, n)
                if ( a[i][j] != 0 )
                {
                    while ( a[i + 1][j] == 0 && i < n )
                    {
                        swap(a[i + 1][j], a[i][j]);
                        ++ i;
                        flag = true;
                    }
                }
        if ( flag == false ) finish(u - 1);
    }
    // left; 2;
    else if ( x == 2 )
    {
        bool flag = false;
        REP(j, 1, n)
            REP(i, 1, n)
                if ( a[i][j] != 0 )
                {
                    while ( a[i][j - 1] == 0 && j > 1 ) 
                    {
                        swap(a[i][j - 1], a[i][j]);
                        -- j;
                        flag = true;
                    }
                }
        mem(vis);
        REP(j, 2, n)
        {
            REP(i, 1, n)
            {
                if ( a[i][j - 1] != 0 && a[i][j - 1] == a[i][j] && vis[i][j] == false && vis[i][j - 1] == false ) 
                {
                    vis[i][j - 1] = true;
                    a[i][j - 1] += a[i][j];
                    a[i][j] = 0;
                    flag = true;
                    W += a[i][j - 1];
                }
            }
        }
        REP(j, 1, n)
            REP(i, 1, n)
                if ( a[i][j] != 0 )
                {
                    while ( a[i][j - 1] == 0 && j > 1 )
                    {
                        swap(a[i][j - 1], a[i][j]);
                        -- j;
                        flag = true;
                    }
                }
        if ( flag == false ) finish(u - 1);
    }
    // right; 3;
    else if ( x == 3 )
    {
        bool flag = false;
        for ( int j = n; j >= 1; -- j )
            REP(i, 1, n)
                if ( a[i][j] != 0 )
                {
                    while ( a[i][j + 1] == 0 && j < n ) 
                    {
                        swap(a[i][j + 1], a[i][j]);
                        ++ j;
                        flag = true;
                    }
                }
        mem(vis);
        for ( int j = n - 1; j >= 1; -- j )
        {
            REP(i, 1, n)
            {
                if ( a[i][j + 1] != 0 && a[i][j + 1] == a[i][j] && vis[i][j] == false && vis[i][j + 1] == false ) 
                {
                    vis[i][j + 1] = true;
                    a[i][j + 1] += a[i][j];
                    a[i][j] = 0;
                    flag = true;
                    W += a[i][j + 1];
                }
            }
        }
        for ( int j = n; j >= 1; -- j )
            REP(i, 1, n)
                if ( a[i][j] != 0 )
                {
                    while ( a[i][j + 1] == 0 && j < n )
                    {
                        swap(a[i][j + 1], a[i][j]);
                        ++ j;
                        flag = true;
                    }
                }
        if ( flag == false ) finish(u - 1);
    }
}

int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    scanf("%d%d", &n, &m);
    int u1, u2, v1, v2, w1, w2;
    scanf("%d%d%d%d%d%d", &u1, &v1, &w1, &u2, &v2, &w2);
    a[u1][v1] = w1;
    a[u2][v2] = w2;
    REP(i, 1, m)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        Move(u, i);
        int cnt = 0;
        REP(i, 1, n)
            REP(j, 1, n) 
                if ( a[i][j] == 0 ) ++ cnt;
        v = 1 + v % cnt;
        cnt = 0;
        REP(i, 1, n)
            REP(j, 1, n)
                if ( a[i][j] == 0 )
                {
                    ++ cnt;
                    if ( cnt == v ) 
                    {
                        a[i][j] = w;
                    }
                }
    }
    ans = W;
    finish(m);
    return 0;
}
