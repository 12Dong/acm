#include<iostream>
#include<algorithm>
using namespace std;
//yr
int num[110];
int main()
{
	int n,v;
	while(cin >> n >> v)
	{
		int sum=0;
		for(int i=0;i<n;i++)
		{
			cin >>num[i];
			sum+=num[i];
		}
		sort(num,num+n);
		if(sum-num[n-1]>v) cout <<"NO"<<endl;
		else cout <<"YES"<<endl;
	}
}
