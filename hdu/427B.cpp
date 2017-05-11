#include<iostream>
#include<cstring>
using namespace std;
int num[200005];
int flag[200005];
int sum[200005];
int main()
{
	int n,t,c;
	while(cin >> n >> t >> c)
	{
		memset(flag,0,sizeof(flag));
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++)
		{
			cin >>num[i];
			if(num[i]>t) flag[i]=1;
		}
		int ans=0;
		int judge=0; 
		for(int i=1;i<=c;i++)
		{
			judge=judge+flag[i];
		}
//		cout << "judge "<<judge<< endl;
		if(judge==0) ans++;
//		cout << "ans "<< ans <<endl; 
		for(int i=1+c;i<=n;i++)
		{
			judge-=flag[i-c];
			judge+=flag[i];
			if(judge==0) ans++;
		}
		cout <<ans << endl;
	}
}
