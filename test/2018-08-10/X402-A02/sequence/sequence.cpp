#include<bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for ( int i = (a), _end_ = (b); i <= _end_; ++ i )
#define mem(e) memset ( (a), 0, sizeof ( a ) )
#define str(a) strlen ( a ) 
typedef long long LL;
template<class T> int maxx(T a, T b) { return a > b ? a : b; }
template<class T> int minn(T a, T b) { return a < b ? a : b; } 
template<class T> int abss(T a) { return a > 0 ? a : -a; }

int n, ans, a[10], p[100][10];
int vis[10];

inline bool pd() 
{
    REP(i, 2, n) if ( vis[i] && !vis[i - 1] ) return false;
    return true;
}

inline void DFS(int x)
{
    if ( x == n + 1 ) 
    {
        if ( pd() ) ++ ans;
        if ( ans > 1004535809 ) ans -= 1004535809;
        return ;
    }
    REP(i, 1, n) { vis[i] ++ ; a[x] = i; DFS(x + 1); vis[i] -- ; }
}

int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    scanf("%d", &n); 
    DFS(1);
    printf("%d\n", ans);
    return 0;
}

/*
 * 4!+4!/2!*3+4!/3!*2+4!/2!/2!+4!/4!
 * 24+36+8+6+1
 * 5!+5!/2!*4+5!/3!*3+5!/4!*2+5!/2!/2!*3+5!/3!/2!*2+5!/5!
 * 541
 * */
