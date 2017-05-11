#include<iostream>
#include<cstring>
using namespace std;
int dir[4][2]={1,0,0,1,-1,0,0,-1};
int times;
int vis[30][30];
int x,y;
char map[30][30];
void dfs(int sx,int sy)
{
	if(sx<0 || sx>=x) return ;
	if(sy<0 || sy>=y) return ;
	if(vis[sx][sy]) return ;
	if(map[sx][sy]=='#') return ;
	vis[sx][sy]=1;
//	cout <<sx <<"   "<<sy<<endl;
//	cout <<map[sx][sy]<<endl;
	if(map[sx][sy]=='.')times++;
	for(int i=0;i<4;i++)
	dfs(sx+dir[i][0],sy+dir[i][1]);
}
int main()
{
	while(cin >> y >> x)
	{
		if(x==0 && y==0 ) break ;
		int sx,sy;
		times=0;
		memset(vis,0,sizeof(vis));
		memset(map,'\0',sizeof(map));
		for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
		{
			cin >> map[i][j];
			if(map[i][j]=='@')
			{
				sx=i;
				sy=j;
			}
		}
		dfs(sx,sy);
		times++;
		cout <<times <<endl;
		
	}
}
