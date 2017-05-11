#include<iostream>
#include<cstring>
using namespace std;
int map[30][30];
int vis[30][30];
int dir[4][2]={1,0,-1,0,0,-1,0,1};
int x,y;
int sx,sy;
int ex,ey;
int Times;
void dfs(int sx,int sy,int times)
{
	if(sx<0 || sx>=x) return ;
	if(sy<0 || sy>=y) return ;
	if(times>=10) return ;
	if(map[sx][sy]==3)  
	{
		Times=min(Times,times);
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int tx=sx+dir[i][0];
		int ty=sy+dir[i][1];
		if(map[tx][ty]==1) continue;
		while(map[tx][ty]!=1 && tx>=0 && tx<x && ty>=0 && ty<y)
		{
			if(map[tx][ty]==3) 
			{
				Times=min(times+1,Times);
				return ;
			}
			tx+=dir[i][0];
			ty+=dir[i][1];
			
		}
		if(tx<0 || tx>=x) continue ;
		if(ty<0 || ty>=y) continue ;
		map[tx][ty] = 0;
		dfs(tx-dir[i][0],ty-dir[i][1],times+1);
		map[tx][ty]=1;
	}
	return ;


}
int main()
{
	while(cin >> y >>x)
	{
		if(x==0 && y==0)break ;
		Times=0x3f3f3f3f;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<x;i++)
		{
			for(int j=0;j<y;j++)
			{
				cin >> map[i][j];
				if(map[i][j]==2)
				{
					sx=i;
					sy=j;
				}
				else if(map[i][j]==3)
				{
					ex=i;
					ey=j;
				}
			}
		}
		dfs(sx,sy,0);
		if(Times==0x3f3f3f3f) cout <<"-1"<<endl;
		else cout << Times <<endl;
		
		}
	}

