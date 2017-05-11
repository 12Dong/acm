#include<iostream>
#include<cstring>
using namespace std;
int num[110][110];
int dp[110][110];
/*
int main()
{
	int n;
	cin >>n;
	while(n--)
	{
		memset(dp,0,sizeof(dp));
		int row;
		cin >> row;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin >> num[i][j];
			  
		    }
	    }
	    
	    for(int i=1;i<=row;i++)
	    {
	    	for(int j=1;j<=i;j++)
	    	{
	    		dp[i][j]=max(dp[i][j],dp[i-1][j]+num[i][j]);
	    		dp[i][j]=max(dp[i][j],dp[i-1][j-1]+num[i][j]);
			}
		}
		int ans=-0x3f3f3f3f;
		for(int i=1;i<=row;i++)
		{
			ans=max(ans,dp[row][i]);
		}
		cout << ans <<endl;
}

}
*/
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		memset(dp,0,sizeof(dp));
		int row;
		cin >> row;
		for(int i=1;i<=row;i++)
		{
			for(int j=1;j<=i;j++)
			{
				cin >> num[i][j];
			}
		}
		for(int i=1;i<=row;i++)
		{
			dp[row][i]=num[row][i];
		}
		for(int i=row-1;i>=1;i--)
		{
			for(int j=1;j<=i;j++)
			{
				dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+num[i][j];
			}
		}
		cout << dp[1][1]<<endl;
	}
}
