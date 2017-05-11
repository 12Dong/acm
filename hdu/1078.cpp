#include<iostream>
#include<cstring>
using namespace std;
int dp[105][105];
int map[105][105];
int n,k;
int dfs(int x,int y)
{
	if(dp[x][y])
	return dp[x][y];
	int up;
	if(x-k<0) up=0;
	else up=x-k;
	int down;
	if(x+k>=n) down=n-1;
	else down=x+k;
	int left;
	if(y-k<0) left=0;
	else left=y-k;
	int right;
	if(y+k>=n) right=n-1;
	else right=y+k;	
	int Max=0;
	
	for(int loc=left;loc<=right;loc++)
	{
		if(map[x][loc]>map[x][y])
		{
			int  tmp=dfs(x,loc);
			Max=max(tmp,Max);
		}
	}
	for(int loc=up;loc<=down;loc++)
	{
		if(map[loc][y]>map[x][y])
		{
			int  tmp=dfs(loc,y);
			Max=max(tmp,Max);
		}
	}
	dp[x][y]=Max+map[x][y];
	return dp[x][y];
}
int main()
{
	while(cin >>n >>k)
	{
		memset(dp,0,sizeof(dp));
		if(n==-1 && k==-1) break;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			cin  >> map[i][j];
		}
		cout << dfs(0,0)<<endl;
	}
 } 
