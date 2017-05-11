#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int vis[100005];
int main()
{
	int n;
	int flag;
	while(cin >> n)
	{
		memset(vis,0,sizeof(vis));
		int num;
		int t=n;
		for(int i=n;i>=1;i--)
		{
			cin >> num;
			vis[num]++;
			flag=0;
			while(vis[t]==1)
			{
				if(flag==0)
				{
					cout << t ;
					flag=1;
				}
				else 
				{
					cout << " " << t;
				}
				t--; 
			}
			cout <<endl;
		}
	}
}
