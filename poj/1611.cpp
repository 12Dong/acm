#include<iostream>
#include<cstring>
using namespace std;
#define N 30005
int fa[N];
int tmp[N];
void init(int n)
{
	for(int i=0;i<n;i++)
	{
		fa[i]=i; 
	}
}
int find(int x)
{
	if(fa[x]==x)
	{
		return fa[x];
	}
	else 
	{
		return fa[x]=find(fa[x]);
	}
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x!=y)
	{
		fa[x]=y;
	}
}
int main()
{
	int n,m;
	while(cin >> n >>m)
	{
		if(n==0 && m==0) break;

		init(n);
		int x,y;	
		for(int i=1;i<=m;i++)
		{
			int k;
			cin >> k;
			int flag;
			int tmp;
			for(int i=0;i<k;i++)
			{
				if(i==0)
				{
					cin >> tmp;
					flag=tmp;
				}
				else 
				{
					cin >> tmp;
					merge(tmp,flag);
				}
			}

		}
		int cnt=1;
		for(int i=1;i<n;i++)
		{
			if(find(i)==find(0))
			{
				cnt++;
			}
		}
		cout << cnt <<endl;
	}
}
