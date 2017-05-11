#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int node[4*100000+5];
int add[4*100000+5];
void pushup(int step)
{
	node[step]=node[step*2]+node[step*2+1];
}
void pushdown(int ln,int rn,int step)
{
	if(add[step])
	{
		add[step*2]=add[step];
		add[step*2+1]=add[step];
		node[step*2]=ln*add[step];
		node[step*2+1]=rn*add[step];
		add[step]=0;
	}
	return ;
}
void build(int l,int r,int step)
{
	if(l==r) 
	{
		node[step]=1;
		return ;
	}
	int m=(l+r)/2;
	build(l,m,step*2);
	build(m+1,r,step*2+1);
	pushup(step);
}
void update(int ll,int rr,int change,int l,int r,int step)
{
	
	if(l==ll && r==rr )
	{
		add[step]=change;
		node[step]=change*(r-l+1);
		return ;
	}
	int m=(l+r)/2;
	pushdown(m-l+1,r-m,step);
	if(rr<=m) update(ll,rr,change,l,m,step*2);
	else if(ll>m) update(ll,rr,change,m+1,r,step*2+1);
	else
	{
		update(ll,m,change,l,m,step*2);
		update(m+1,rr,change,m+1,r,step*2+1);
	}
	pushup(step);
}
int main()
{
	int cases;
	cin >> cases;
	for(int i=1;i<=cases;i++)
	{
		memset(add,0,sizeof(add));
		int t;
		cin >> t;
		build(1,t,1);
		int times;
		scanf("%d",&times);
		while(times--)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			update(x,y,z,1,t,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",i,node[1]);
	}
}
