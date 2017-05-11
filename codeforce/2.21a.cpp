#include<iostream>
#include<algorithm> 
using namespace std;
int main()
{
	int n;
	int num[100005];
	while(cin >> n)
	{
		int Max=-1;
		int Min=0x3f3f3f3f;
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
			Max=max(Max,num[i]);
			Min=min(Min,num[i]);
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			if(num[i]>Min && num[i]<Max)
			ans++;
		}
		cout << ans <<endl;
	}
}
