#include<iostream>
using namespace std;
//yr
int main()
{
	char map[30][30];
	int n,m;
	int Case=1;
	while(cin >> n >> m)
	{
		for(int i=1;i<=n;i++)
		{
			map[i][1]='A'+i-1;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=2;j<=m;j++)
			{
				if(j<=i)
				map[i][j]=map[i][j-1]-1;
				else 
				map[i][j]=map[i][j-1]+1;
			}
		}
		cout << "Case "<< Case++ << endl;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cout<<map[i][j];
			}
			cout << endl;
		}
	}
}
