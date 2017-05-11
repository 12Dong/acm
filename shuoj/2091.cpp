#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
const int N=1005;

typedef long long ll;
typedef pair<int,int> PII;
vector <PII> G[N]; 
int vis[N];
int dis[N];
void init(int n)
{
	for(int i=0;i<=n;i++)
		G[i].clear(); 
}
void add_edge(int u,int v,int d)
{
	G[u].push_back(make_pair(v,d));
}
void spfa(int s,int n)
{
	queue<int> q;
	q.push(s);
	memset(vis,0,sizeof(vis));
	vis[s]=1;
	for(int i=0;i<=n;i++)
		dis[i]=(i==s?0:INF);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		for(int i=0;i<G[x].size();i++)
		{
			int y=G[x][i].first;
			int d=G[x][i].second;
			if(dis[y]>dis[x]+d)
			{
				dis[y]=dis[x]+d;
				if(vis[y]==0)
				{
						q.push(y);
						vis[y]=1;
				}
			}
		}
	}
}
int map[505][505];
int main()
{
	int n;
	int t;
	int l;
	cin >> t;
	while(t--)
	{
		cin >> n >> l;
		memset(map,0,sizeof(map));
		init(n);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				map[i][j]=INF;
			}
		}
		for(int i=0;i<l;i++)
		{
			int u,v,d;
			cin >> u >> v >> d;
			add_edge(u,v,d);
			map[u][v]=d;
		}
		int Min=INF;
		spfa(0,n);
		for(int i=0;i<n;i++)
		{
			Min=min(dis[i]+map[i][0],Min);
		 } 
		 if(Min>=INF)
		 {
		 	cout << -1 << endl;
		 }
		 else 
		 {
		 	cout << Min << endl;
		 }
	}
}
