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
#define abs abss

const int maxn = 210;

int a[maxn], n, m, ans2, ans3, ans4, p[maxn], t[maxn];
int num[maxn], Min = 1000000000;
double ans1 = 1000000000.0;

inline void DFS(int x, int sum, int hiahia)
{
    if ( sum > m ) return ;
    if ( hiahia > Min ) return ;
    if ( x == n + 1 ) 
    {
        if ( sum == m ) 
        {
            int cnt = 0, sum2, sum3 = 0, sum4;
            REP(i, 1, n) if ( t[i] ) p[++ cnt] = a[i];
            sort ( p + 1, p + cnt + 1 );
            double sum1 = sum * 1.0 / cnt;
            if ( cnt == 1 || cnt == 2 ) sum2 = p[1];
            else sum2 = (cnt % 2 == 0) ? p[cnt / 2 - 1] : p[cnt / 2];
            mem(num);
            REP(i, 1, cnt) num[p[i]] ++;
            REP(i, 1, m) sum3 = max(sum3, num[i]);
            sum4 = p[cnt] - p[1];
            if ( hiahia == Min )  
            {
                ans1 = min(ans1, sum1);
                ans2 = min(ans2, sum2);
                ans3 = min(ans3, sum3);
                ans4 = min(ans4, sum4);
            }
            else if ( hiahia < Min )
            {
                Min = hiahia;
                ans1 = sum1; ans2 = sum2; ans3 = sum3; ans4 = sum4;
            }
        }
        return ;
    }
    t[x] = 1;
    DFS(x + 1, sum + a[x], hiahia + 1);
    t[x] = 0;
    DFS(x + 1, sum, hiahia);
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
    scanf("%d%d", &n, &m);
    REP(i, 1, n) scanf("%d", &a[i]);
    ans2 = ans3 = ans4 = 1000000000;
    DFS(1, 0, 0);
    printf("%.7lf %d %d %d", ans1, ans2, ans3, ans4);
    return 0;
}
