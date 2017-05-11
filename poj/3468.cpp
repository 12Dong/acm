#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
ll node[4*100000+5];
ll add[4*100000+5];
void pushup(int step)
{
    node[step]=node[step*2]+node[step*2+1];
}
void pushdown(int ln,int rn,int step)
{
	if(add[step])
	{
	add[step*2]+=add[step];
	add[step*2+1]+=add[step];
	node[step*2]+=(ll)ln*add[step];
	node[step*2+1]+=(ll)rn*add[step];
	add[step]=0; 
    }
    return ;
}
void build(int l,int r,int step)
{
	add[step]=0;
	if(l==r) 
	{
		scanf("%lld",&node[step]);
		return ;
	}
	int m=(l+r)/2;
	build(l,m,step*2);
	build(m+1,r,step*2+1);
	pushup(step);
}
void update(int ll,int rr,long long  change,int l,int r,int step)
{
	if(ll==l && rr==r)
	{
		add[step]+=change;
		node[step]+=change*(r-l+1);
		return ;
	}
	int m=(l+r)/2;
	pushdown(m-l+1,r-m,step);
	if(rr<=m)
	{
		update(ll,rr,change,l,m,step*2);
	}
	else if(ll>m)
	{
		update(ll,rr,change,m+1,r,step*2+1);
	}
	else 
	{
		update(ll,m,change,l,m,step*2);
		update(m+1,rr,change,m+1,r,step*2+1);
	}
	pushup(step);
	return ;
}
ll query(int ll,int rr,int l,int r,int step)
{
	if(ll==l && rr==r)
	{
		return node[step];
	}
	int m=(l+r)/2;
	pushdown(m-l+1,r-m,step);
	if(rr<=m)
	{
		return query(ll,rr,l,m,step*2);
	}
	else if(ll>m)
	{
		return query(ll,rr,m+1,r,step*2+1);
	}
	else 
	{
		return query(ll,m,l,m,step*2)+query(m+1,rr,m+1,r,step*2+1);
	}
}
int main()
{
	int n,q;
	while(cin >> n >> q)
	{
		build(1,n,1);
		char c;
		ll x,y,z;
		for(int i=0;i<q;i++)
		{
			scanf("%*c %c",&c);
			if(c=='Q')
			{
				scanf("%lld %lld",&x,&y);
				cout <<query(x,y,1,n,1)<<endl;
			 } 
			else 
			{
				scanf("%lld %lld %lld",&x,&y,&z);
				update(x,y,z,1,n,1);
			}
		}

	}
		return 0;
 } 
