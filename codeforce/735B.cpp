#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
bool cmp(double a,double b)
{
	return a>b;
}
double num[1000005];
int main()
{
	int n,n1,n2;

	while(cin >> n >> n1 >> n2)
	{
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		sort(num,num+n,cmp);
		int n3=min(n1,n2);
		int n4=max(n1,n2);
		double sum3=0;
		double sum4=0;
		int i=0;
//		cout << "OK"<<endl;
		for(i=0;i<n3;i++)
		{
			sum3+=num[i];
		}
//		cout << sum3 <<endl;
		for(int j=i;j<i+n4;j++)
		{
			sum4+=num[j];
		}
//		cout << sum4 <<endl;
		double ans=sum3/n3+sum4/n4;
		printf("%0.8lf\n",ans);
	}
}
