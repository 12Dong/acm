#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> PII;
const int MAXN=1010;
vector<PII> G[MAXN];
int vis[MAXN];
int dis[MAXN];
int cnt[MAXN];
void add_edge(int u,int v,int d)
{
	G[u].push_back(make_pair(v,d));
}
void init(int n)
{
	for(int i=0;i<n;i++)
	G[i].clear();
}
void spfa(int s,int n)
{
	for(int i=1;i<=n;i++)
	dis[i]=(i==s?0:INF);
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	queue<int>q;
	q.push(s);
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
				if(!vis[y])
				{
					q.push(y);
					vis[y]=1;
				}
			}
		}
	}
}
int main()
{
	int n;
	int cases=0;
	while(cin >> n)
	{
		init(n);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int d;
				cin >> d;
				if(d==-1) continue;
				else 
				{
					add_edge(i,j,d);
					add_edge(j,i,d);
				}
			}
		}
		int x,y;
		cin >> x >> y;
		spfa(x,n);
		cout <<"Case "<<++cases<<endl;
		cout << dis[y]<<endl;
	}
}
