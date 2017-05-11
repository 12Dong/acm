#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int n,p;
#define N 100005
double a[N],b[N],t[N];

bool judge(double x)
{
	double cnt=0;
	for(int i=1;i<=n;i++)
	{
		t[i]=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		t[i]-=a[i]*x;
		if(t[i]<0)
		{
			cnt+=fabs(t[i]);
		}
	}
	return cnt<=x*p;
}

/*
bool judge(double x)
{
	for(int i=1;i<=n;i++)
		t[i]=b[i];
	for(int i=1;i<=n;i++)
		t[i]-=a[i]*x;
	double cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(t[i]<0)
			cnt+=fabs(t[i])/p;
	}
	return cnt<=x;
}
*/
int main()
{
	while(cin >> n >> p)
	{
		double suma=0;
		for(int i=1;i<=n;i++)
		{
			cin >> a[i] >> b[i]; 
			suma+=a[i];
		}
		if(suma<=p) 
		{
			cout << -1 << endl;
			continue; 
		}
		double l=0,r=9e17;
		double ans;
		for(int i=0;i<150;i++)
		{	
			double mid=1.0*(l+r)/2;
			if(judge(mid))
			{
				ans=mid;
				l=mid;
			}
			else 
			{
				r=mid;
			}
		}	
		printf("%.10lf\n",ans);	
	 } 
}
