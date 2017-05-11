#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Node
{
	int w;
	int s;
	int id;
}node[1100];
struct DP
{
	int val;
	int prem;
}dp[1100];
bool cmp(Node a,Node b)
{
	if(a.w==b.w) return a.s>b.s;
	else return a.w<b.w; 
}
void output(int status)
{
	if(dp[status].prem==0) return;
	output(dp[status].prem);
	cout <<node[ dp[status].prem].id<<endl;
}
int G[1100][1100];
int main()
{
	int x,y;
	int i=0;
	while(scanf("%d %d",&x,&y)!=EOF)
	{
		node[i].w=x; node[i].s=y;  node[i].id=i+1;
		i++;
	}
	sort(node,node+i-1,cmp);
	for(int j=0;j<i;j++)
	{
		dp[j].val=1;
		for(int k=j+1;k<i;k++)
		{
			if(node[j].w!=node[k].w)
			if(node[j].s>node[k].s)
			G[j][k]=1;
		}
	}
	for(int j=0;j<i;j++)
	{
		for(int k=j+1;k<i;k++)
		{
			if(G[j][k])
			{
				dp[k].val=max(dp[j].val+1,dp[k].val);
				if(dp[k].val==dp[j].val+1) dp[k].prem=j;
				 
			}
		}
	}
	int Max=-1;
	int ans;
	for(int j=0;j<i;j++)
	{
		if(Max<dp[j].val)
		{
			Max=dp[j].val;
			ans=j;
		}
	}
	cout << dp[ans].val<<endl;
	output(ans);
	cout << node[ans].id<<endl;
}
