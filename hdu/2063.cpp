#include<iostream>
#include<queue>
#include<cstring>
int G[1100][1100];
int x[1100];
int y[1100];
int vis[1100];
int m,n;
using namespace std;
int searchpath(int k)
{
	for(int i=1;i<=m;i++)
	{
		if(G[k][i]==1 && !vis[i])
		{
			vis[i]=1;
			if(y[i]==-1 || searchpath(y[i]))
			{
				y[i]=k;
				x[k]=i;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int k;
	while(true)
	{
		cout <<"�����������" <<endl; 
		cin >> k;
		if(k==0) break;
		cout << "������Ů������������"<<endl;
		cin >> m >> n;
		memset(G,0,sizeof(G));
		memset(x,-1,sizeof(x));
		memset(y,-1,sizeof(y));
		int a,b;
		cout << "������Ů��xϲ������y ��x y "<<endl;
		for(int i=0;i<k;i++)
		{
			cin >> b >> a;
			G[a][b]=1;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			ans+=searchpath(i);
		}
		cout <<"��������Ϊ"<<endl;
		cout << ans <<endl;
	}
	}

