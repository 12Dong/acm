#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//yr
int n;
double  len;
double li[1005];
int main()
{
	while(cin >> n >> len)
	{
		for(int i=0;i<n;i++)
		{
			cin >> li[i];
		}
		double  l=0,r=len;   
		double ans;
		sort(li,li+n);    
		ans=max(li[0],len-li[n-1]); //第一盏灯到街头距离 和 最后一盏灯到街尾距离 
		 for(int i=0;i<n-1;i++)
		 {
		 	double d=(li[i+1]-li[i])/2;
		 	ans=max(ans,d);
		 }
		 printf("%0.10lf\n",ans);
		
	}
}
