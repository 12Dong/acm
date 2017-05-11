#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
#define N 50000
#define mid (l+r)/2
#define lson step*2
#define rson step*2+1
struct cow
{
	int Max;
	int Min;
} cows[N*4+5];
void pushup(int step)
{
	cows[step].Max=max(cows[lson].Max,cows[rson].Max);
	cows[step].Min=min(cows[lson].Min,cows[rson].Min);
}
void build(int l,int r,int step)
{
	
	if(l==r)
	{
		int weight;
		scanf("%d",&weight);
		cows[step].Max=weight;
		cows[step].Min=weight;
		return ;
	}
	build(l,mid,lson);
	build(mid+1,r,rson);
	pushup(step);
}
cow query(int ll,int rr,int l,int r,int step)
{
	if(ll==l && rr==r)
	{
		return cows[step];
	}
	if(rr<=mid) return query(ll,rr,l,mid,step*2);
	else if(ll>mid) return query(ll,rr,mid+1,r,step*2+1);
	else 
	{
		cow tmp1=query(ll,mid,l,mid,step*2);
		cow tmp2=query(mid+1,rr,mid+1,r,step*2+1);
		cow ans;
		ans.Max=max(tmp1.Max,tmp2.Max);
		ans.Min=min(tmp1.Min,tmp2.Min);
		return ans;
	}
}

int main()
{
	int n,q;
	while(scanf("%d%d",&n,&q)==2)
	{
		build(1,n,1);
		int x,y;
		for(int i=0;i<q;i++)
		{
			scanf("%d %d",&x,&y);
			cow Cow=query(x,y,1,n,1);
			cout << Cow.Max-Cow.Min<<endl;
		}
/*		for(int i=0;i<30;i++)
		{
			cout << cows[i].Max <<"  ";
		}
*/

/*		cout <<endl;
		for(int i=0;i<30;i++)
		{
			cout << cows[i].Min <<"  ";
		}
		cout <<endl;
		
*/
	}
}
