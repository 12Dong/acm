#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 105
bool vis[N];
char map[N][N];
bool tmp[N];
int n,m;
bool judge(int p)
{
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<n;i++)
	{
		if(vis[i]) continue;
		if(map[i][p]>map[i-1][p])
		{
			tmp[i]=1;
		}
		else if(map[i][p]<map[i-1][p])
		{
			return true;
		}
	}
	return false;
 } 
 int main()
 {
 	while(cin >> n >> m)
 	{
 		memset(vis,0,sizeof(vis));
 		int ans=0;
 		for(int i=0;i<n;i++)
 		{
 			scanf("%s",map[i]);
		 }
		for(int i=0;i<m;i++)
		{
			if(judge(i))
			{
				ans++;
			}
			else
			{
				for(int j=0;j<n;j++)
				{
					vis[j]=vis[j]+tmp[j];
				}
			}
		}
		cout << ans << endl;
	 }
 }
