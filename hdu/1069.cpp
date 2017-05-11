#include<iostream>
#include<cstring> 
#include<algorithm>
using namespace std;
struct Node
{
	int x,y;
	int h;
	int s;
	
}node[1000];
bool cmp(Node a,Node b)
{
	return a.s >=b.s;
}
int G[1000][1000];
int vis[500];
int dp[1000];
int main()
{
	int cases=0;
	int n;
	while(cin >>n)
	{
		if(n== 0) break;
		cases++;
		memset(dp,0,sizeof(dp));
		memset(vis,0,sizeof(vis));
		memset(G,0,sizeof(G));
		
		for(int i=0;i<n;i++)
		{
			int x,y,z;
			cin >> x >> y >> z;
			node[i].x=x; node[i].y=y; node[i].h=z; node[i].s=x*y; 
			node[i+n].x=y; node[i+n].y=z; node[i+n].h=x; node[i+n].s=y*z; 
			node[i+2*n].x=x; node[i+2*n].y=z; node[i+2*n].h=y; node[i+2*n].s=x*z; 
		}
		n=3*n;
		sort(node,node+n,cmp);
		for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
		{
			if(node[i].x>node[j].x && node[i].y>node[j].y)
			G[i][j]=1;
			else if(node[i].y>node[j].x && node[i].x>node[j].y)
			G[i][j]=1;
		}
		for(int i=0;i<n;i++) dp[i]=node[i].h;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<i;j++)
			{
				if(G[j][i])
				dp[i]=max(dp[j]+node[i].h,dp[i]);
			}
		}
		int ans=-1;
		for(int i=0;i<n;i++) ans=max(ans,dp[i]);
		printf("Case %d: maximum height = %d\n",cases,ans);
	}
}
