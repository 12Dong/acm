#include<iostream>
using namespace std;
#define N 1005
bool vis[N];
int fa[N];
void init(int n)
{
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		vis[i]=0;
	}
}
int find(int x)
{
	if(fa[x]==x)
	{
		return fa[x];
	}
	else 
	{
		return fa[x]=find(fa[x]);
	}
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		fa[x]=y;
	}
}
void dfs(int x,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]) 
		{
			if(find(i)==find(x))
			{
				vis[i]=1;
			}
		}
	}
}
int main()
{	
	int times;
	cin >> times;
	while(times--)
	{
		int n,m;
		cin >> n >> m;
		init(n);
		int x,y;
		for(int i=1;i<=m;i++)
		{
			cin >> x >> y;
			merge(x,y);
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cnt++;
				vis[i]=1;
				dfs(i,n);
			}
		}
		cout << cnt <<endl;
	}	
}
