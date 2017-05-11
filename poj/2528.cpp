#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=10010;
bool cover[MAXN*8];
struct node
{
	int l,r;
}posters[MAXN];
int x[MAXN*2];
int hash[10000005];
void build(int l,int r,int step)
{
	cover[step]=false;
	if(l==r)
	{
		return ;
	 } 
	 int m=(l+r)/2;
	 build(l,m,step*2);
	 build(m+1,r,step*2+1);
} 
bool update(int ll,int rr,int l,int r,int step)
{
	if(cover[step]==true) return false;
	if(ll==l && rr==r)
	{
		cover[step]=true;
		return true;
	}
	bool result;
	int mid=(l+r)/2;
	if(rr<=mid) update(ll,rr,l,mid,step*2);
	else if(ll>mid) update(ll,rr,mid+1,r,step*2+1);
	else 
	{
		bool b1=update(ll,mid,l,mid,step*2);
		bool b2=update(mid+1,rr,mid+1,rr,step*2+1);
		result=b1 || b2 ;
	}
	if(cover[step*2] && cover[step*2+1])
	cover[step]=true;
	return result;
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		int n;
		scanf("%d",&n);
		int count=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&posters[i].l,&posters[i].r);
			x[count++]=posters[i].l;
			x[count++]=posters[i].r;
		}
		sort(x,x+count);
		count=unique(x,x+count)-x;
		for(int i=0;i<count;i++)
		{
			hash[x[i]]=i;
		}
		build(0,count-1,1);
		int res=0;
		for(int i=n-1;i>=0;i--)
		{
			if(update(hash[posters[i].l],hash[posters[i].r],0,count-1,1))
			res++;
		}
		cout << res <<endl;
	}
	return 0;
}
