#include<iostream>
#include<cstring>	
int num[300005];
int vis[300004];
using namespace std;
int main()
{

	int n;
	while(cin >> n)
	{
		memset(vis,0,sizeof(vis));
		int ans=0;
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		for(int i=0;i<n;i++)
		{
			if(vis[i]) continue;
			int Max=num[i];
			ans++;
			for(int j=i;j<n;j++)
			{
				if(vis[j]) continue;
				if(num[j]<=Max)
				{
					Max=num[j];
					vis[j]=1;
				}
			}
 		}
 		cout << ans <<endl;

	}
}

