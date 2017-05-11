#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//yr
typedef long long ll;
ll n,m,w;
ll num[100005];
ll need[100005];
ll v[100005];   //标记那一朵浇过了 超过这朵则去除这朵浇过的 
int main()
{
	while(scanf("%lld %lld %lld",&n,&m,&w)==3)
	{
		ll Min=0x3f3f3f3f,Max=-1;
		ll ans;
		for(int i=0;i<n;i++)
		{
			scanf("%lld",&num[i]);
			if(num[i]>Max)
			{
				Max=num[i];
			}
			if(num[i]<Min)
			{
				Min=num[i];
			}
		}
			Max+=m;
			ll l=Min,r=Max;
			

			while(l<=r)
			{
//				cout  << ans << endl; 
				memset(v,0,sizeof(v));// 浇过花的标记 过了这个标记则将watered去除相应 
				ll mid=(l+r)/2;
				
				for(ll i=0;i<n;i++)
				{
					need[i]=max(mid-num[i],ll(0)); // 需要浇多少天水 
				}
				ll watered=0;//已浇水
				ll restday=m;//还剩下的日子
				for(int i=0;i<n;i++)
				{
					watered+=v[i];	//其实一直再减 
					need[i]-=watered;
					if(need[i]>0)
					{
						restday-=need[i];
						if(restday< 0 )  break;
						watered+=need[i];
						v[i+w]-=need[i];	
						need[i]=0;
					}	
				}		
				if(restday<0)
					r=mid-1; 
				else
				{
					ans=mid;
					l=mid+1;
				}
			}
		printf("%lld\n",ans);	
		}
		
	}
