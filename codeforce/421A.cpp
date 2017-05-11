#include<iostream>
#include<cstring>
using namespace std;

//yr
int vis[105];
int main()
{
	int n,a,b;
	while(cin >> n >> a >> b)
	{
		memset(vis,0,sizeof(vis));
		int num;
		for(int i=1;i<=a;i++)
		{
			
			cin >> num;
			vis[num]=1;
		}
		for(int i=1;i<=b;i++)
		{
			cin >> num;
			vis[num]=2;
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=n) cout << vis[i]<<" ";
			else cout << vis[i]<<endl;
		}
	}
}
