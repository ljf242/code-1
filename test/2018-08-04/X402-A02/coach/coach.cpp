/**************************************************************
	File name: coach.cpp
	Author: huhao
	Email: 826538400@qq.com
	Create time: 8/4/2018, 10:52:26 AM
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
int main()
{
	freopen("coach.in","r",stdin);
	freopen("coach.out","w",stdout);
	read();read();
	fr(i,1,read()-1)read();
	printf("%d\n",read());
	return 0;
}