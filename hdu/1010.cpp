#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
char map[10][10];
int vis[10][10];
int n,m,t,ex,ey,sx,sy;
int flag;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void dfs(int ex,int ey,int T)
{
	if(ex<0 || ex >= n) return ;
	if(ey<0 || ey >= m) return ;
	if(map[ex][ey]=='X') return ;
	if(vis[ex][ey]) return ;
	if(T>t) return ;
	if((abs(sx-ex)+abs(sy-ey))%2!=(t-T)%2)
	return ;

	if(flag) return;
	if(ex==sx && ey==sy && t==T) 
	{
		flag=1;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		vis[ex][ey]=1;
		dfs(ex+dir[i][0],ey+dir[i][1],T+1);
		vis[ex][ey]=0;
	}
}
int main()
{
	while(cin >> n >> m >> t)
	{
		if(n==0 && m==0 && t==0) break;
		flag=0;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cin >> map[i][j];
				if(map[i][j]=='S')
				{
					sx=i;
					sy=j;
				}
				else if(map[i][j]=='D')
				{
					ex=i;
					ey=j;
				}
			}
		}
		dfs(ex,ey,0);
		if(flag) cout <<"YES"<<endl;
		else cout <<"NO"<<endl;
		
		
	}
}
