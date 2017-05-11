#include<iostream>
using namespace std;
int main()
{
	int num[1100];
	int dp[1100];
	int n;
	while(cin >> n)
	{
		if(n==0) break;
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
			dp[i]=num[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(num[i]<num[j])
				{
					dp[j]=max(dp[i]+num[j],dp[j]);
				}
			}
		}
		int ans=-1;
		for(int i=0;i<n;i++)
		ans=max(ans,dp[i]);
		cout << ans <<endl;
		
	}
}
