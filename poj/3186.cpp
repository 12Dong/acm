#include<iostream>
#include<cstring>
using namespace std;
int dp[1100][1100];
int num[1100];
int main()
{

	int n;
	while(cin >> n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		cin >> num[i];
		for(int len=1;len<=n;len++)
		{
			for(int s=1;s+len-1<=n;s++)
			{
				int e=s+len-1;
				if(s==e) dp[s][e]=num[s]*n;  //num[s]最后一个取 该附加值必定为num[s]*n;
				else 
				{
					dp[s][e]=max(dp[s][e],dp[s+1][e]+(n-len+1)*num[s]);
					dp[s][e]=max(dp[s][e],dp[s][e-1]+(n-len+1)*num[e]);
				}
			}
		}
		cout << dp[1][n] <<endl;
	}
}
