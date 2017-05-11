#include<iostream>
#include<cstring>
using namespace std;
int num[50005];
struct Node
{
	int lson,rson;
	int val;
}node[4*50000+5];
void  pushup(int step)
{
	node[step].val=node[step*2].val+node[step*2+1].val;
}
void build(int l,int r,int step)
{
	if(l==r)
	{
		scanf("%d",&node[step].val);
		return ;
	}
	int m=(l+r)/2;
	build(l,m,step*2);
	build(m+1,r,step*2+1);
	pushup(step);

}
void update(int loc,int l,int r,int add,int step)
{
	if(l==r)
	{
		node[step].val+=add;
		return ;
	}
	int m=(l+r)/2;
	if(loc<=m) update(loc,l,m,add,step*2);
	else if(loc>=m+1) update(loc,m+1,r,add,step*2+1);
	pushup(step);
}
int  query(int ll,int rr,int l,int r,int step)
{
	if(ll==l && rr==r) return node[step].val;
	int m=(l+r)/2;
	if(rr<=m)  return query(ll,rr,l,m,step*2);
	else if(ll>m) return query(ll,rr,m+1,r,step*2+1);
	else return query(ll,m,l,m,step*2)+query(m+1,rr,m+1,r,step*2+1);
}
int main()
{
	int cases;
	scanf("%d",&cases);
	char str[100];
	for(int f=1;f<=cases;f++)
	{
		int t;
		scanf("%d",&t);
		build(1,t,1);
		int x,y;
		int flag=0;
		printf("Case %d:\n",f);
		while(scanf("%s",str)==1)
		{
			if(str[0]=='E')  break;
			scanf("%d %d",&x,&y);
			if(str[0]=='Q') cout << query(x,y,1,t,1)<<endl;
			else if(str[0]=='A') update(x,1,t,y,1);
			else if(str[0]=='S') update(x,1,t,-y,1);


		}	}
	return 0;
}
