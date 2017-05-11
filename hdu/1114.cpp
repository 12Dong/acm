#include<iostream>
#include<cstring>
using namespace std;
#define N 10005
#define INF 0x3f3f3f3f
int dp[N];
int v[N];
int w[N];
int main()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int x,y;
		memset(v,0,sizeof(v));
		memset(w,0,sizeof(w));
		memset(dp,INF,sizeof(dp));
		cin >>x >> y;
		int V=y-x;
		int n;
		cin >> n;
		
		for(int i=0;i<n;i++)
		{
			cin >> v[i] >> w[i];
		}
		dp[0]=0;
		for(int i=0;i<n;i++)
		{
			for(int j=w[i];j<=V;j++)
			{
				dp[j]=min(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		if(dp[V]==INF)
		{
			cout <<"This is impossible." <<endl;
		}
		else 
		{
			cout << "The minimum amount of money in the piggy-bank is "<<dp[V]<<'.'<<endl;
		}
		}
	}
