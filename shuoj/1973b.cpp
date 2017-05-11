#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
struct Node
{
	int l,r;
	int add;
	int y0,y1,y2;
}node[4*100000+5];
void pushup(int step)
{
	node[step].y0=node[step*2].y0+node[step*2+1].y0;
	node[step].y1=node[step*2].y1+node[step*2+1].y1;
	node[step].y2=node[step*2].y2+node[step*2+1].y2;
}
void pushdown(int step)
{
	if(node[step].add)
	{
		int n=node[step].add;
		n=n%3;
		while(n--)
		{
			node[step*2].add++;
			int t0=node[step*2].y0;
			int t1=node[step*2].y1;
			int t2=node[step*2].y2;
			node[step*2].y1=t0;
			node[step*2].y2=t1;
			node[step*2].y0=t2;
			node[step*2+1].add++;
			t0=node[step*2+1].y0;
			t1=node[step*2+1].y1;
			t2=node[step*2+1].y2;
			node[step*2+1].y1=t0;
			node[step*2+1].y2=t1;
			node[step*2+1].y0=t2;			
		}
		
	}
	node[step].add=0;
}
void build(int l,int r,int step)
{
	node[step].y0=0;
	node[step].y1=0;
	node[step].y2=0;
	node[step].l=l;
	node[step].r=r;
	node[step].add=0;
	if(l==r)
	{
		node[step].y0=1;
	}
	else
	{
		int m=(l+r)/2;
		build(l,m,step*2);
		build(m+1,r,step*2+1);
		pushup(step);
	}
}
void update(int l,int r,int step)
{
	if(l==node[step].l && r==node[step].r)
	{
		node[step].add++;
		int t0=node[step].y0;
		int t1=node[step].y1;
		int t2=node[step].y2;
		node[step].y1=t0;
		node[step].y2=t1;
		node[step].y0=t2;
		return ;
	}
	pushdown(step);
	int m=(node[step].l+node[step].r)/2;
	if(r<=m) update(l,r,step*2);
	else if(l>m) update(l,r,step*2+1);
	else 
	{
		update(l,m,step*2);
		update(m+1,r,step*2+1);
	}
	pushup(step);
}
int query(int l,int r,int step)
{
	if(node[step].l==l && node[step].r==r)
	{
		return node[step].y0;
	}
	pushdown(step);
	int m=(node[step].l+node[step].r)/2;
	if(r<=m) return query(l,r,step*2);
	else if(l>m) return query(l,r,step*2+1);
	else 
	{
		return query(l,m,step*2)+query(m+1,r,step*2+1);
	 } 
}
int main()
{
	int n,q,t,l,r;
	scanf("%d%d",&n,&q);
	build(1,n,1);
	while(q--)
	{
		scanf("%d%d%d",&t,&l,&r);
		if(t==0)
		update(l,r,1);
		else 
		cout << query(l,r,1)<<endl;
	}
}
