#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num[35];
	int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		sort(num,num+n);
		int ans=1;
		int cnt=1;
		for(int i=1;i<n;i++)
		{
			cout << num[i-1]<<" ";
			if(num[i]==num[i-1]) cnt++;
			else 
			{
				ans=max(ans,cnt);
				cnt=1;
			}
		}
		cout << num[n-1]<<endl;
		cout << ans <<endl; 
	}
}
