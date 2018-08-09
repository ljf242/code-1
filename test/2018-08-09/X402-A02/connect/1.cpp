#include<bits/stdc++.h>
#define re register
using namespace std;

struct node{
    int u,v,w;
}e[1000010];
int cmp(node a,node b){
    return a.w>b.w;
}
int f[1000010];
int find(int x){
    return f[x]==x?f[x]:f[x]=find(f[x]);
}
void join(int x,int y){
    x=find(x);y=find(y);
    if(x!=y)f[y]=x;
}
int main(){
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    int n,m,sum=0;
    scanf("%d%d",&n,&m);
    for(re int i=1;i<=m;i++){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
        sum+=e[i].w;
    }
    sort(e+1,e+m+1,cmp);
    for(re int i=1;i<=n;i++)f[i]=i;
    int in=0;
    for(re int i=1;i<=m;i++){
        int u=e[i].u,v=e[i].v;
        if(find(u)!=find(v)){
            join(u,v);sum-=e[i].w;
            in++;if(in==n-1)break;
        }
    }
    printf("%d\n",sum);
    return 0;
}
