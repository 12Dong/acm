#include<iostream>
#include<cstring>
using namespace std;
int dp[1100];
int num[1100];
int N[1100];
/*
int main()
{
	int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			dp[i]=1;
		}
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(num[j]>num[i]) dp[j]=max(dp[j],dp[i]+1);
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
*/
int main()
{
	int n;
	while(cin >> n)
	{
		memset(N,0,sizeof(N));
		for(int i=0;i<n;i++)
		{
			dp[i]=1;
		}
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		N[1]=num[0];
		int len=1;
		for(int i=1;i<n;i++)
		{
			if(num[i]>N[len])
			{
				N[++len]=num[i];
			}
			else if(num[i]<N[len]) 
			{
				int left=1;
				int right=len;
				int mid;
				while(left<right)
				{
					mid=(left+right)/2;
					if(N[mid]>=num[i]) right=mid;
					else left=mid+1;
				}
				N[right]=num[i];
			}
		}
		cout <<len<<endl;
	}
}

