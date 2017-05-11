#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n;
	int num[1100];
	int dp[1100];
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
			dp[i]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(num[i]>num[j])
				{
					dp[i]=max(dp[i],dp[j]+1);
				}
			}
		}
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			ans=max(ans,dp[i]);
		}
		cout << ans <<endl;
	}
 } 
