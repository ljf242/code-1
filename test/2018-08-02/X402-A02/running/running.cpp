/**************************************************************
	File name: running.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 8/2/2018, 8:34:33 AM
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(long long i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(long long i=(a),_end_=(b);i>=_end_;i--)
long long read()
{
	long long r=0,t=1,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
namespace run
{
	#define mod 998244353
	#define N 100010
	#define H 110
	#define fo(i,a) for(long long i=begin[a];i;i=next[i])
	long long power(long long x,long long y,long long p)
	{
		long long r=1;
		while(y)
		{
			if(y&1)r=r*x%p;
			y>>=1;x=x*x%p;
		}
		return r;
	}
	long long n,begin[N],next[N<<1],to[N<<1],siz[N],h[N],e,w[N],f[N],ans,o[N],p[N];
	int t[N][H],k[N][H<<1];
	void add(long long u,long long v)
	{
		e++;
		to[e]=v;
		next[e]=begin[u];
		begin[u]=e;
	}
	void dfs1(long long u)
	{
		long long v;siz[u]=1;
		fo(i,u)if(f[u]!=(v=to[i]))
		{
			f[v]=u;h[v]=h[u]+1;
			dfs1(v);
			siz[u]+=siz[v];
		}
	}
	long long dfs2(long long u)
	{
		long long v,mm=0;t[u][0]=1;
		fo(i,u)if(f[u]!=(v=to[i]))
		{
			long long m=dfs2(v)+1;
			fr(j,1,m)t[u][j]+=t[v][j-1];
			mm=max(mm,m);
		}
		o[u]=mm;
		return mm;
	}
	void dfs3(long long u,long long m)
	{
		long long v;k[u][0]=1;p[u]=m;
		fo(i,u)if(f[u]!=(v=to[i]))
		{
			fr(j,0,m)k[v][j+1]=k[u][j];
			fr(j,1,o[u])k[v][j+1]=((k[v][j+1]+t[u][j]-t[v][j-1])%mod+mod)%mod;
			dfs3(v,max(m,o[u])+1);
		}
	}
	int main()
	{
		freopen("running.in","r",stdin);
		freopen("running.out","w",stdout);
		n=read();
		fr(i,1,n-1)
		{
			long long u=read(),v=read();
			add(u,v);add(v,u);
		}
		fr(i,1,n)w[i]=read();
		h[1]=1;dfs1(1);dfs2(1);
		fr(i,1,n)
			if(w[i])
			{
				long long v;
				fo(j,i)if(f[i]!=(v=to[j]))
					ans=(ans+1ll*t[v][w[i]-1]*(n-siz[v]))%mod;
			}
			else ans=(ans+n)%mod;
		dfs3(1,0);
		fr(i,1,n)if(w[i])
			ans=(ans+1ll*k[i][w[i]]*siz[i])%mod;
		printf("%lld\n",ans*power(n*n%mod,mod-2,mod)%mod);
		return 0;
	}
}
int main(){return run::main();}