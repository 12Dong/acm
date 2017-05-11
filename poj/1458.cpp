#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int dp[1100][1100];
int main()
{
	string a,b;
	while(cin >> a >> b)
	{
		memset(dp,0,sizeof(dp));
		int len1=a.size();
		int len2=b.size();
		for(int i=0;i<=len1;i++) dp[i][0]=0;
		for(int i=0;i<=len2;i++) dp[0][i]=0;
		for(int i=0;i<len1;i++)
		{
			for(int j=0;j<len2;j++)
			{
				if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1;
				else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			
			}
		}
			
			cout << dp[len1][len2]<<endl;
			
		}
	}
