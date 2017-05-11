#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char str1[55];
	char str2[55];
	int dp[55][55];
	int cases;
	cin >> cases;
	for(int k=1;k<=cases;k++)
	{
		memset(str1,0,sizeof(str1));
		memset(str2,0,sizeof(str2));
		memset(dp,0,sizeof(dp));
		int x,y;
		cin >>x  >> y;
		for(int i=0;i<x;i++)
		cin >> str1[i];
		for(int i=0;i<y;i++)
		cin >> str2[i];
		for(int i=0;i<=x;i++) dp[i][0]=0;
		for(int i=0;i<=y;i++) dp[0][i]=0;
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				if(str1[i]==str2[j]) dp[i+1][j+1]=dp[i][j]+1;
				else dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
			}
		}
		printf("Case %d\n",k);
		cout << dp[x][y]<<endl;
		
	}
}
