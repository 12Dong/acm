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
		ans=max(li[0],len-li[n-1]); //��һյ�Ƶ���ͷ���� �� ���һյ�Ƶ���β���� 
		 for(int i=0;i<n-1;i++)
		 {
		 	double d=(li[i+1]-li[i])/2;
		 	ans=max(ans,d);
		 }
		 printf("%0.10lf\n",ans);
		
	}
}
