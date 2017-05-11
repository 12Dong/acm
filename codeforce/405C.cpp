#include<iostream>
#include<cstdio>
using namespace std;
int Matrix[1005][1005];
int n;
int ans;
int cul()
{
	int ans=Matrix[0][0];
	for(int i=1;i<n;i++)
		ans=ans^Matrix[i][i];
	return ans;
}
void changerow(int row)
{
	for(int i=0;i<n;i++)
	{
		Matrix[row-1][i]=1-Matrix[row-1][i];
	}
}
void changecol(int col)
{
	for(int i=0;i<n;i++)
	{
		Matrix[i][col-1]=1-Matrix[i][col-1];
	}
}
int main()
{
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				scanf("%d",&Matrix[i][j]);
			}
		}
		ans = cul();
		int q;
		scanf("%d",&q);
		int order=0;
		for(int i=0;i<q;i++)
		{
			int x,y;
			scanf("%d",&x);
			if(x==3) 
			{
				printf("%d",ans);
			}
			else 
			{
				scanf("%d",&y);
				if(Matrix[y][y]==0) ans=(ans+1)%2;
				else ans=((ans-1)+2)%2;
			}
		}
	}
}
