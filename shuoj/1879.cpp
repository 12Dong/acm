#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//yr
typedef long long ll;
const int N=100005;
bool check1(ll num)
{
	
}
int num[N];
int main()
{
	int n,m;
	while(scanf("%lld %lld",&n,&m)==2)
	{
		memset(num,0,sizeof(num));
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&num[i]);
		}
		for(int i=0;i<m;i++)
		{
			ll x;
			scanf("%lld",&x);
			ll l=0,r=n-1;
			ll ans1=-1;
			ll ans2=-1;
			ll ans3=-1;
			ll ans4=-1;
			
			while(l<=r)
			{
				ll mid=(l+r)/2;
				if(num[mid]<x)
				{
					ans1=mid;
					l=mid+1;
				}
				else
				{
					r=mid-1;
				}
			}
			l=0,r=n-1;
			while(l<=r)
			{
				
				ll mid=(l+r)/2;
				if(num[mid]<=x)
				{
					ans2=mid;
					l=mid+1;
				}
				else
				{
					r=mid-1;
				}
			}
			l=0,r=n-1;
			while(l<=r)
			{
				ll mid=(l+r)/2;
				if(num[mid]>x)
				{
					ans3=mid;
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}
			l=0,r=n-1;
			while(l<=r)
			{
				ll mid=(l+r)/2;
				if(num[mid]>=x)
				{
					ans4=mid;
					r=mid-1;
				}
				else
				{
					l=mid+1;
				}
			}	
			if(ans1==-1) printf("-1 ");
			else
			{
				printf("%lld ",ans1+1);
			}		
			
			if(ans2==-1) printf("-1 ");
			else
			{
				printf("%lld ",ans2+1);
			}
			
			if(ans3==-1) printf("-1 ");
			else
			{
				printf("%lld ",ans3+1);
			}
			if(ans4==-1) printf("-1\n");
			else
			{
				printf("%lld\n",ans4+1);
			}
		}
	}
}
