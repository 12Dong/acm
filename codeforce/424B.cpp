#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
const int N=1000000;
using namespace std;
//yr
struct Point
{
	double x;
	double y;	
	double r;
	int p;
}point[1005];
bool cmp(Point a,Point b)
{
	return a.r<b.r;
}
int main()
{
	int n,p;
	while(cin >> n >> p)
	{
		memset(point,0,sizeof(point));
		for(int i=0;i<n;i++)
		{
			cin >> point[i].x>>point[i].y>>point[i].p;
			point[i].r=sqrt(point[i].x*point[i].x+point[i].y*point[i].y);
		}
		double ans=0;
		sort(point,point+n,cmp);
		for(int i=0;i<n;i++)
		{
			if(p>=N) break;
			p+=point[i].p;
			ans=point[i].r;
		}
		if(p>=N)
			printf("%0.7lf\n",ans);
		else 
			cout << -1 << endl;
	}
}
