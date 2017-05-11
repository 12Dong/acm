#include<iostream>
#include<cstring>
using namespace std;
char map[110][110];
bool vis[110][110];
int times;
int x,y;
int dir[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};
void dfs(int sx,int sy)
{
	if(sx<0 || sx>=x) return ;
	if(sy<0 || sy>=y) return ;
	if(map[sx][sy]=='.') return ;
	if(vis[sx][sy]) return ;
	vis[sx][sy]=true;
	for(int i=0;i<8;i++)
	dfs(sx+dir[i][0],sy+dir[i][1]);
}
int  main()
{
	while(cin >> x >> y)
	{
		memset(map,'\0',sizeof(map));
		memset(vis,0,sizeof(vis));
		times=0;
		for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
		cin >> map[i][j];
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				if(map[i][j]=='W'&& !vis[i][j])
				{
					times++;
					dfs(i,j);
				}
			}
		}
		cout << times << endl;
		
	}
	return  0;
}
