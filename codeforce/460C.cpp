#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//yr
typedef long long ll;
ll n,m,w;
ll num[100005];
ll need[100005];
ll v[100005];   //�����һ�佽���� ���������ȥ����佽���� 
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
				memset(v,0,sizeof(v));// �������ı�� ������������wateredȥ����Ӧ 
				ll mid=(l+r)/2;
				
				for(ll i=0;i<n;i++)
				{
					need[i]=max(mid-num[i],ll(0)); // ��Ҫ��������ˮ 
				}
				ll watered=0;//�ѽ�ˮ
				ll restday=m;//��ʣ�µ�����
				for(int i=0;i<n;i++)
				{
					watered+=v[i];	//��ʵһֱ�ټ� 
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
