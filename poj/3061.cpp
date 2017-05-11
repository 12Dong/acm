#include<iostream>
using namespace std;
int num[110000];
int main()
{
	int times;
	cin >> times;
	for(int i=1;i<=times;i++)
	{
		int n,lim;
		cin >> n >> lim;
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		int s=0,e=0;
		int sum=0;
		int ans=0x3f3f3f3f;
		while(1)
		{
			while(e<n && sum<lim ) sum+=num[e++];
			if(sum < lim) break;
			ans=min(ans,e-s);
			sum-=num[s++];
		}
		if(ans==0x3f3f3f3f) cout << 0 <<endl;
		else cout << ans <<endl;
	}
 } 
