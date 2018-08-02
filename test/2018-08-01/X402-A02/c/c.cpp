/**************************************************************
	File name: c.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 8/1/2018, 9:51:30 AM
**************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int r=0,t=1,c=getchar();
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
#define N 10
#define M 4
struct arr
{
	int h,l;
	int a[N][M];
	arr()
	{
		h=l=0;
		fr(i,0,N-1)fr(j,0,M-1)a[i][j]=0;
	}
}k;
int n,m=4;
int calc(arr a)
{
	int c=0;
	fr(i,0,n-1)
		fr(j,0,m-1)
			if(a.a[i][j])
				c+=abs(a.a[i][j]/4-i)+min(abs(a.a[i][j]%4-j),4-abs(a.a[i][j]%4-j));
	return c;
}
bool operator<(arr a,arr b)
{
	return a.h+a.l==b.h+b.l?a.h<b.h:a.h+a.l>b.h+b.l;
}
#include<queue>
priority_queue<arr>q;
int mx[4]={0,0,1,-1},my[4]={1,-1,0,0};
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();
	fr(i,0,n-1)fr(j,0,m-1)k.a[i][j]=read()-1;
	k.l=calc(k);
	q.push(k);
	while(!q.empty())
	{
		k=q.top();q.pop();
		if(k.l==0){printf("%d\n",k.h);return 0;}
		int x,y;
		fr(i,0,n-1)fr(j,0,m-1)if(!k.a[i][j]){x=i;y=j;}
		fr(i,0,3)
		{
			int xx=x+mx[i],yy=y+my[i];
			if(xx<0||xx>=n)continue;
			if(yy<0)yy+=m;if(yy>=m)yy-=m;
			arr kk=k;swap(kk.a[x][y],kk.a[xx][yy]);
			kk.h=k.h+1;kk.l=calc(kk);
			q.push(kk);
		}
	}
	return 0;
}