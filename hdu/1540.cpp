#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
#define N 50000
struct Node
{
	int l,r;
	int ls,rs,ms;
 } node[N*4+5];
 void build(int l,int r,int step)
 {
 	node[step].l=l;
 	node[step].r=r;
 	node[step].ls=node[step].rs=node[step].ms=node[step].r-node[step].l+1;
 	if(l==r)
 	{
 		return ;
	 }
	 int mid=(l+r)/2;
	 build(l,mid,step*2);
	 build(mid+1,r,step*2+1);
 }
 void update(int e,int loc,int step)
 {
 	if(node[step].l==node[step].r)
 	{
 		if(e==1) 
 		{
 			node[step].ls=node[step].rs=node[step].ms=1;
		}
		else if(e==0)
		{
			node[step].ls=node[step].rs=node[step].ms=0;
		}
		return ;
	 }
	 int mid=(node[step].l+node[step].r)/2;
	 if(loc<=mid) update(e,loc,step*2);
	 else if(loc>mid) update(e,loc,step*2+1);
	 if(node[step*2].ls==node[step*2].r-node[step].l+1)
	 {
	 	node[step].ls=node[step*2].ls+node[step*2+1].ls;
	 }
	 else 
	 {
	 	node[step].ls=node[step*2].ls;
	 }
	 if(node[step*2+1].rs==node[step*2+1].r-node[step*2+1].l+1)
	 {
	 	node[step].rs=node[step*2+1].rs+node[step*2].rs;
	 }
	 else 
	 {
	 	node[step].rs=node[step*2+1].rs;
	 }
	 node[step].ms=max(max(node[step*2].ms,node[step*2+1].ms),node[step*2].rs+node[step*2+1].ls);
//   s[k].ms=max(max(s[2*k].ms,s[2*k+1].ms),s[2*k].rs+s[2*k+1].ls);
 }
 int query(int loc,int step)
 {
 	if(node[step].l==node[step].r || node[step].ms==0 || node[step].ms==node[step].r-node[step].l+1)
 	{
 		return node[step].ms;
	 }
	 int mid=(node[step].r+node[step].l)/2;
	 if(loc<=mid)
	 {
	 	if(loc>=node[step*2].r-node[step*2].rs+1)
	 	{
	 		return node[step*2].rs+node[step*2+1].ls;
		 }
		else 
		{
			return query(loc,step*2);
		}
	 }
	 else 
	 {
	 	if(loc<=node[step*2+1].l+node[step*2+1].ls-1)
	 	{
	 		return node[step*2].rs+node[step*2+1].ls;
		 }
		 return query(loc,step*2+1);
	 }
}
void debug(int step)
{
	if(node[step].l==node[step].r)
	{
		cout << node[step].l<< "   "<<endl;
		cout << node[step].ls <<"   "<< node[step].rs << "   " << node[step].ms<<endl;
		return ;
	}
	int mid=(node[step].r-node[step].l)/2;
	debug(step*2);
	debug(step*2+1);
}

int main()
{
	int n,q;
	stack <int> s;
	while(scanf("%d%d",&n,&q)==2)
	{
		build(1,n,1);
		
		for(int i=0;i<q;i++)
		{
			char c;
			int x;
			cin >> c;
			if(c=='D') 
			{
				cin >> x;
				update(0,x,1);
				s.push(x);
			}
			else if(c=='R')
			{
				
				int tmp=s.top();
				s.pop();
				update(1,tmp,1);
			}
			else if(c=='Q')
			{
				cin >> x;
				cout << query(x,1) <<endl;
			}
//			cout << i <<endl;
		}
//		debug(1);
	}
	
}
