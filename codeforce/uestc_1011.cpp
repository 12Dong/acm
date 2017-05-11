#include<iostream>
#include<cstring>
using namespace std;

//thanks to pyf ...

#define N 1000

int dp[N][N]; 
int Map[N][N];
int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n; 
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
			{
				cin >> Map[i][j];
			}
//					
		for(int i=0;i<n;i++)
			dp[n-1][i] = Map[n-1][i];
		for(int i=n-2;i>=0;i--)
		{
			for(int j=0;j<=i;j++)
			{
				dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + Map[i][j];
			}
		}
		cout << dp[0][0] << endl;
	}
}
