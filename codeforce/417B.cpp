#include<iostream>
#include<cstring>
using namespace std;
#define N 100005
int num[N];
int main()
{
	int cases;
	while(cin >> cases )
	{
		bool flag=1;
		memset(num,0,sizeof(num));
		for(int i=0;i<cases;i++)
		{
			int x,k;
			cin >> x >> k;
			if(x>num[k])
			{
				flag=0;
			}
			else if( x== num[k])
			{
				num[k]++;
			}
			else 
			{
				continue;
			}
		}
		if(flag) cout << "YES"<<endl;
		else cout << "NO"<< endl;
	}
}
