#include<iostream>
using namespace std;
int node[4*200000+5];
void pushup(int step)
{
	node[step]=max(node[step*2],node[step*2+1]);
}
void build(int l,int r,int step)
{
	if(l==r)
	{
		scanf("%d",&node[step]);
		return ;
	}
	int m=(l+r)/2;
	build(l,m,step*2);
	build(m+1,r,step*2+1);
	pushup(step);
}
void update(int loc,int l,int r,int change,int step)
{
	if(l==r)
	{
		node[step]=change;
		return ;
	}
	int m=(l+r)/2;
	if(loc<=m) update(loc,l,m,change,step*2);
	else if(loc>m) update(loc,m+1,r,change,step*2+1);
	pushup(step); 
}
int  query(int ll,int rr,int l,int r,int step)
{
	if(ll==l && rr==r)
	{
		return node[step];
	}
	int m=(l+r)/2;
	if(rr<=m) return query(ll,rr,l,m,step*2);
	else if(ll>m) return query(ll,rr,m+1,r,step*2+1);
	else return max(query(ll,m,l,m,step*2),query(m+1,rr,m+1,r,step*2+1));
}
int main()
{
	int x,y;
	while(scanf("%d %d",&x,&y)==2)
	{
		build(1,x,1);
		char c;
		int n,m;
		for(int i=0;i<y;i++)
		{
			scanf("%*c %c %d %d",&c,&n,&m);
			if(c=='Q') cout << query(n,m,1,x,1) <<endl;
			else if(c=='U') update(n,1,x,m,1);
		}
		
	}
	return 0;
}
