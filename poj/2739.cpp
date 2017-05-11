#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100005
int vis[MAX];
int prime[MAX];
void init_prim()
{
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=2;i<=MAX;i++)
	{
		if(!vis[i])
		{
			prime[cnt++]= i;
			for(int j=2;i*j<=MAX;j++)
			{
				vis[i*j]=1;
			}
		}
	}
}
int main()
{
	init_prim();
	int n;
	while(cin >> n && n)
	{
		int l=0,r=0;
		int el=0,er=0;
		int sum=0;
		int ans=0;
		while(1)
		{
			while(sum<n && prime[r]<=n)
			{
				sum+=prime[r++];
//				cout << sum <<endl;
			}
			if(sum<n) break;
			if(sum==n) ans++;
			sum-=prime[l++]; 
		}
		cout << ans <<endl;
	}
}
