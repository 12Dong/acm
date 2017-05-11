#include<iostream>
using namespace std;
int pri[11000];
int minpri[11000];
#define MAX 0x3f3f3f3f
struct node
{
	int x,y;
	int v;
}dp[11000];
int main()
{
	int x;
	while(scanf("%d",&x)==1&&x)
	{
		int flag=0;
		for(int i=0;i<=x;i++)
		minpri[i]=0;
		int ansx,ansy;
		for(int i=1;i<=x;i++)
		{
			int num;
			cin >> num;
			if(num>=0) flag=1;
			pri[i]=pri[i-1]+num;
			if(pri[minpri[i-1]]>pri[i]) minpri[i]=i;
			else minpri[i]=minpri[i-1];
		}
		if(flag==0) 
		{
			cout << 0  << " "<<pri[1] <<" "<<pri[x]-pri[x-1]<<endl;
			continue;
		}
		int ans=-999;
		minpri[1]=0;
		for(int i=1;i<=x;i++)
		{
//			cout << ansx <<"   "<<ansy <<endl;
			if(ans<pri[i]-pri[minpri[i]])
			{
				
				ansx=minpri[i]+1;
				ansy=i;
				ans=pri[i]-pri[minpri[i]];
//				cout << ansx <<"************"<<ansy <<endl;
			}
		}
		cout << pri[ansy]-pri[minpri[ansy]] <<" "<<pri[ansx]-pri[ansx-1]<<" "<<pri[ansy]-pri[ansy-1] <<endl;
//		cout << ansx <<endl;
//		cout << ansy <<endl;
	}
}
