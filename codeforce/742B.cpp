#include<iostream>
#include<cstring>
using namespace std;
int num[100005*3];
int vis[100005*3];
int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		memset(vis,0,sizeof(vis));
		long long ans=0;
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
			ans+=vis[num[i]^k];
			vis[num[i]]++;
		}

		cout << ans <<endl;
	}
}
