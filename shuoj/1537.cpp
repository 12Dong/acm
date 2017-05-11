#include<iostream>
#include<cstring>
using namespace std;
#define N 30000005
int fa[N];
int vis[N];
void init(int n)
{
	for(int i=0;i<=N;i++)
	fa[i]=i;
}
int find(int x)
{
	if(fa[x]==x) return fa[x];
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=fa[x];
	y=fa[y];
	if(x!=y)
	{
		fa[x]=y;
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m;
		cin >> n >> m;
		init(n);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<m;i++)
		{
			int x,y;
			cin >> x >> y;
			merge(x,y);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				ans++;
				for(int j=i+1;j<=n;j++)
				{
					if(!vis[j])
					{
						if(find(i)==find(j))
						{
							vis[j]=1;
						}
					}
				}
			}
		}
		cout << ans <<endl;
	}
}

