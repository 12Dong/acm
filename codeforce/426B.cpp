#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
//yr
int map[110][110];
int n,m;
bool check(int c)
{
	for(int i=1;i<=c;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(map[i][j]!=map[2*c-i+1][j]) return false;
		}
	}
	return true;
}
int main()
{
	while(cin >> n >> m)
	{
		memset(map,0,sizeof(map));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&map[i][j]);
			}
		}
		int c=n;
		int ans=n;
		while(c%2==0)
		{
			c=c/2;
			if(check(c)) 
			{
				ans=c;
			}
			else
			{
				break;
			}
		}
		printf("%d\n",ans);
	}
}
