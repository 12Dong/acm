#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n;
int vis[1005];
int G[1005][1005];
int deg[1005];

bool bfs()
{
	queue<int> q;
	q.push(1);
	while(!q.empty())
	{
		int tmp=q.front();
		q.pop();
		for(int i=1;i<=n;i++)
		{
			if(vis[i]) continue;
			if(G[tmp][i])
			{
				vis[i]=1;
				q.push(i);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0) return false;
	}
	return true;
	
}
/*
bool bfs()
{
    int i, t;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        for (i = 1; i <= n; i++)
        {
            if (!vis[i] && G[t][i])
            {
                q.push(i);
                vis[i] = 1;
            }

        }
    }
    for (i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            return false;
        }
    }
    return true;
}
*/
int main()
{
	int q;
    while(cin >> n)
    {
    	if(n==0) break;
        cin >> q;
        memset(deg, 0, sizeof(deg));
        memset(vis, 0, sizeof(vis));
        memset(G, 0, sizeof(G));
		for(int i=0;i<q;i++)
		{
			int x,y;
			cin >> x >> y;

			G[x][y]=1;
			G[y][x]=1;
			deg[x]++;
			deg[y]++;

/*           deg[a]++;
            deg[b]++;
           G[a][b] = G[b][a] = 1;
*/
		}
		bool ans=true;
		for(int i=1;i<=n;i++)
		{
			if(deg[i]%2==1)
			{
				ans=false;
//				cout <<"ERROR"<<endl;
				break;
			}
		}

        for (int i = 1; i <= n; i++)  
        {
            if (deg[i] & 1)
            {
                ans = false;
                break;
            }
        }
       if (ans==false) 
        {
            cout << "0" << endl;
        }
        else if (bfs())
        {
            cout << "1"<<endl;
        }
        else
        {
            cout << 0 <<endl;
        }
/*        for(int i=1;i<=n;i++)
        cout << deg[i]<<"   ";
*/
	}
	return 0;
}
