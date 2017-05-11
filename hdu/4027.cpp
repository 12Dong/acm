#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
#define N 100000
#define mid (l+r)/2
__int64 num[N*4+5];
void pushup(int step)
{
	num[step]=num[step*2]+num[step*2+1];
}
void build(int l,int r,int step)
{
	if(l==r)
	{
		scanf("%I64d",&num[step]);
		return ;
	}
	build(l,mid,step*2);
	build(mid+1,r,step*2+1);
	pushup(step);
}
void update(int ll,int rr,int l,int r,int step)
{
	if(num[step]==(r-l+1))
	{
		return ;
	}
	if(l==r)
	{
		num[step]=sqrt(num[step]);
		return ;
	}
	if(rr<=mid) update(ll,rr,l,mid,step*2);
	else if(ll>mid) update(ll,rr,mid+1,r,step*2+1);
	else 
	{
		update(ll,mid,l,mid,step*2);
		update(mid+1,rr,mid+1,r,step*2+1);
	}
	pushup(step);
}
__int64 query(int ll,int rr,int l,int r,int step)
{
	if(ll==l && rr==r)
	{
		return num[step];
	}
	if(rr<=mid) return query(ll,rr,l,mid,step*2);
	else if(ll>mid) return query(ll,rr,mid+1,r,step*2+1);
	else 
	{
		return query(ll,mid,l,mid,step*2)+query(mid+1,rr,mid+1,r,step*2+1);
	}
}
int main()
{
	int n;
	int k=0;
	while(scanf("%d",&n)==1)
	{

		build(1,n,1);
		int q;
		scanf("%d",&q);
		printf("Case #%d:\n",++k);
		for(int i=0;i<q;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(y>z) 
			{
				int tmp;
				tmp=y;
				y=z;
				z=tmp;
			}
			if(x==0) update(y,z,1,n,1);
			else if(x==1) cout << query(y,z,1,n,1) <<endl;
			
		}
		cout << endl;
/*		for(int i=0;i<4*10+5;i++)
		cout << num[i] <<"  ";
		cout <<endl;
		cout << query(1,10,1,10,1)<<endl;
*/
     
	 }
	}
