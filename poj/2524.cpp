#include<iostream>
#include<cstdio>
using namespace std;
int fa[50005];
int n,m;
void CLR(int x)
{
	for(int i=0;i<=x;i++)
	{
		fa[i]=i;
	}
 } 
int find(int x)
{
	if(fa[x]!=x)
	{
		fa[x]=find(fa[x]);
	}
	return fa[x];
}
void con(int x,int y)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		fa[fx]=fy;
		n--;
	}
}

int main()
{
	int cases=1;
	while(scanf("%d %d",&n,&m)==2)
	{
		if(n==0 && m==0) break ;
		CLR(n);
		for(int i=1;i<=m;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			con(x,y);
		}
		 printf("Case %d: %d\n",cases++,n);
	}
}
