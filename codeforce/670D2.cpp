#include<iostream>
#include<cstring>
using namespace std;
//yr
typedef long long ll;
const ll N=1000005;
const ll M=1000000010;
ll need[N];
ll have[N];
ll n,k;
bool check(ll num)
{
	ll sum=k;
	for(ll i=0;i<n;i++)
	{
		if(have[i]<need[i]*num)
		{
			sum-=need[i]*num-have[i];
		}
//		cout << "****"<<sum <<"    "<< k<<endl;
		if(sum<0) return false; 
	}
	return true;
}
int main()
{
	while(cin >> n >> k)
	{
		for(ll i=0;i<n;i++)
		{
			cin >> need[i];
		}
		for(ll i=0;i<n;i++)
		{
			cin >> have[i];
		}
		ll l=0,r=3000000000ll;
		ll ans=0;
		while(l<=r)
		{
//			cout <<"*****"<< ans<<endl;
			ll mid=(l+r)/2;
//			cout << mid << endl;
			if(check(mid))
			{
				ans=mid;
				l=mid+1;
			}
			else
			{
				r=mid-1;
			}
		}
		cout << ans << endl;
	}
}

