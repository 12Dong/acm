#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
ll num[300005];
int main()
{
	int n;
	while(cin >> n)
	{
		memset(num,0,sizeof(num));
		ll sum=0;
		for(int i=1;i<=n;i++)
		{
			cin >> num[i];
		}
		sort(num+1,num+n+1);
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			if(i!=n)
			{
				ans+=(i+1)*num[i];
			}
			else
			{
				ans+=n*num[i];
			}
		}
		cout << ans << endl;
}
}
