#include<iostream>
#include<cstring>
using namespace std;
#define INF 0x3f3f3f3f
int dp[110*110][15];
int a[110];
int b[110];
int main()
{
	int l,n;
	while(cin >> l >> n)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=l;i++)
		cin >> a[i];
		for(int i=1;i<=l;i++)
		cin >> b[i];
		a[0]=a[l];
		b[0]=b[l];
		for(int i=1;i<15;i++)
		dp[0][i]=INF;
		for(int k=0;k<n;k++)
		{
			for(int i=1;i<=l;i++)
			{
				for(int j=0;j<15;j++)
				{
					if(j==0) dp[i+k*l][j]=dp[i+k*l-1][j+5]+b[i];
					else if(j<10) dp[i+k*l][j]=min(dp[i+k*l-1][j-1]+a[i],dp[i+k*l-1][j+5]+b[i]);
					else if(j==10) dp[i+k*l][j]=min(dp[i+k*l-1][j-1]+a[i],dp[i+k*l-1][14]+a[i]);
					else if(j>10) dp[i+k*l][j]=dp[i+k*l-1][j-1]+a[i];
				}
			}
		}
		int ans=INF;
		for(int i=0;i<15;i++)
		{
			ans=min(ans,dp[l*n][i]);
		}
		cout << ans <<endl;
	}
}
