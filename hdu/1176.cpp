#include<iostream>
#include<cstring>
using namespace std;
int map[110000][20];
int dp[110000][20];
int main()
{
	int n;
	while(cin >> n)
	{
		memset(map,0,sizeof(map));
		memset(dp,-1,sizeof(dp));
		if(n==0) break;
		int T=-1;
		int t,x;
		for(int i=0;i<n;i++)
		{
			cin >> x >> t;
			map[t][x]++;
			T=max(t,T);
		}
		dp[0][5]=0;
		for(int i=0;i<=T;i++)
		{
			for(int j=0;j<=10;j++)
			{
				if(dp[i][j]==-1) continue;
				dp[i+1][j-1]=max(dp[i+1][j-1],dp[i][j]+map[i+1][j-1]);
				dp[i+1][j]=max(dp[i+1][j],dp[i][j]+map[i+1][j]);
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+map[i+1][j+1]);
			}
		}
		int ans=-1;
		for(int i=0;i<=10;i++)
		{
			ans=max(ans,dp[T+1][i]);
		}
		cout << ans <<endl;
		
	}
}
