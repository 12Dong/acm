#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//yr
const int N=1000005;
int num[N];
int dp[N];
int main()
{
	int n;
	dp[0]=0;
	for(int i=0;i<N;i++)
	{
		dp[i]=dp[i-1]^i;
	}
	while(scanf("%d",&n)==1)
	{
		int ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			ans=ans^num[i];
		}
//		cout << ans << endl;
/* TLE
		for(int i=2;i<=n;i++)
		{
			int need=n/i;
			if(need%2==0)
			{
				int cur=n%i;
				for(int j=1;j<=cur;j++)
				{
					ans=ans^(j%i);
				}
			}
			else
			{
				int cur=i+n%i;
				for(int j=1;j<=cur;j++)
				{
					ans=ans^(j%i);
				}
			}
		}
*/
		for(int i=2;i<=n;i++)
		{
			int need=n/i;
			if(need%2==0)
			{
				int cur=n%i;
				ans=ans^dp[cur];
//				cout << "1   "<<ans << endl;
			}
			else
			{
				int cur=n%i;
				ans=ans^dp[cur]^dp[i-1]; 
//				cout << "2   "<<ans << endl;
			}
//			cout << ans << endl;
		}
		cout << ans << endl;
	}
}
