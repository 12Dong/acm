#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("input.txt","r",stdin);
	int n,k;
	cin >> n >> k;
	int vis[1005*3];
	for(int i=1;i<=n;i++)
	{
		cin >> vis[i];
		vis[i+n]=vis[i];
	}
	for(int i=k;i<=k+n;i++)
	{
		if(!vis[i]) continue;
		else 
		{
			freopen("output.txt","w",stdout);
			if(i>n) cout << i-n;
			else cout << i <<endl;
			break;
		}
	}
}
