#include<iostream>
using namespace std;
int vis[1000005];
void f()
{
	for(int i=2;i<=1000005;i++)
	{
		if(!vis[i])
		for(int j=2;j*i<=1000005;j++)
		{
			vis[i*j]=1;
		}
	}
}
int main()
{
	int n;
	f();
	while(cin >> n)
	{
		if(n==1)
		{
			cout << 1 <<endl;
			cout << 1 <<endl;
			continue;
		}
		if(n==2) 
		{
			cout << 1 <<endl;
			cout <<"1 1"<<endl;
			continue;
		}
		cout << 2 <<endl;
		for(int i=2;i<=n;i++)
		{
			if(vis[i]==1) cout <<1<<" ";
			else cout << 2 <<" ";
		}
		if(vis[n+1]==1) cout << 1<<endl;
		else cout <<2 <<endl;
	}
}
