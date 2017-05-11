#include<iostream>
using namespace std;
#define N 50000*4+5
struct Node
{
	int num;
	int l,r;
}node[N];
void pushup(int step)
{
	node[step].num=node[step*2].num+node[step*2+1].num;
}
void build(int root,int l,int r)
{
	if(l==r)
	{
		node[root].l=l;
		node[root].r=r;
		node[root].num=0;
		return ;
	}
	node[root].l=l;
	node[root].r=r;
	node[root].num=0;
	int mid=(l+r)/2;
	build(root*2,l,mid);
	build(root*2+1,mid+1,r);
}
void insert(int root,int num,int loc)
{
	if(node[root].l==node[root].r && node[root].l==loc)
	{
		node[root].num+=num;
		return ;
	}
	int mid=(node[root].l+node[root].r)/2;
	if(loc<=mid)
	{
		insert(root*2,num,loc);
	}
	else
	{
		insert(root*2+1,num,loc);
	}
	pushup(root);
}
int query(int root,int l,int r)
{
	int mid=(l+r)/2;
	if(node[root].l==l && node[root].r==r)
	{
		return node[root].num;
	}
	else if(r<=mid) return query(root*2,l,r);
	else if(l>mid) return query(root*2+1,l,r);
	else 
	{
		return query(root*2,l,mid)+query(root*2+1,mid+1,r);
		
	 } 
}
int main()
{
	int cases;
	scanf("%d",&cases);
	for(int i=1;i<=cases;i++)
	{
		int n;
		cin >> n;
		build(1,1,n);
		for(int j=0;j<n;j++)
		{
			int tmp;
			scanf("%d",&tmp);
			insert(1,tmp,j);
		}
		printf("Case %d:\n",i);
		char s[80];
		while(scanf("%s",s)==1)
		{
			if(s[0]=='E') break;
			int x,y;
			scanf("%d%d",&x,&y);
			if(s[0]=='A') insert(1,x,y);
			if(s[0]=='Q') printf("%d\n",query(1,x,y));
			if(s[0]=='S') insert(1,x,-y);
		}
	
	}
}
