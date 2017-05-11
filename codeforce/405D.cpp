#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//yr
const int N= 1e+6;
int num[N+5];
int ans[N+5]; 
int main()
{
	int n;
	while(scanf("%d",&n)==1)
	{
		memset(num,0,sizeof(num));
		memset(ans,0,sizeof(ans));
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			int Num;
			scanf("%d",&Num);
			num[Num]=1;
		}
		for(int i=0;i<=N;i++)
		{
			if(num[i]==1)
			{
				 if(num[N+1-i]==0)
				 {
				 	ans[cnt++]=N+1-i;
				 	num[N+1-i]=2;
				 	num[i]=2;
				 }
			}
		}
		for(int i=0;cnt!=n;i++)
		{
			if(num[i]==0 && num[N-i+1]==0)
			{
				if(N-i+1>N) continue;
				ans[cnt++]=i;
				ans[cnt++]=N-i+1;
				num[i]=2;
				num[N-i+1]=2;
			}
		}
		cout << cnt << endl;
		for(int i=0;i<cnt;i++)
		{
			if(i==cnt-1) cout << ans[i]<<endl;
			else cout << ans[i] << " ";
		}
	}
}
