#include<iostream>
#include<algorithm>
using namespace std;
struct good
{
	int cur;
	int nex;
	bool vis;
}G[2*100000+5];
bool cmp1(good a,good b)
{
	return a.cur<b.cur;
}
bool cmp2(good a,good b)
{
	return a.nex<b.nex;
}

int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		for(int i=0;i<n;i++)
		{
			cin >> G[i].cur;
			G[i].vis=0;
		}
		for(int i=0;i<n;i++)
		{
			cin >> G[i].nex;
		}
		sort(G,G+n,cmp1);
		int C=0;
		for(int i=0;i<k;i++)
		{
			C+=G[i].cur;
			G[i].vis=1;
		}
		sort(G,G+n,cmp2);
		for(int i=0;i<n;i++)
		{
			if(G[i].vis==0)
			{
				C+=G[i].nex;
			}
		}
		cout <<  C << endl;
	}
}
