#include<iostream>
using namespace std;
struct Node
{
	int need;
	int have;
}node[1100];
int main()
{
	int n,k;
	while(cin >>  n >> k)
	{
		for(int i=0;i<n;i++)
		{
			cin >> node[i].need;
		}
		int ans=0;
		int tmp;
		int Min=0x3f3f3f3f;
		for(int i=0;i<n;i++)
		{
			cin >> node[i].have;
			tmp=node[i].have/node[i].need;
			Min=min(tmp,Min); 
		}
		ans+=Min;
		for(int i=0;i<n;i++)
		{
			node[i].have-=Min*node[i].need;
		}		
//		cout <<"OK"<<endl;
		while(1)
		{
			for(int i=0;i<n;i++)
			{
				if(node[i].have>=node[i].need) node[i].have-=node[i].need;
				else 
				{
					tmp=node[i].need-node[i].have;
					node[i].have=0;
					k-=tmp;
				}
				if(k<0) break;
				if(i==n-1 && k>=0) ans++;
			}
			if(k<0) break;
		}
		cout << ans << endl;
	}
}
