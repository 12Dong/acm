#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
//yr
ll n;
ll p;
ll k;
bool fun(ll ans)
{
	ll tmp=0;
	if(ans < k) tmp+=(k-ans)+(1+ans)*ans/2;
	else if(ans >=k) tmp+=(ans+ans-k+1)*k/2;
	if(ans+k-1<=n) tmp+=(1+ans)*ans/2+(n-k-ans+1);
	else if(ans+k-1>n) tmp+=(ans+ans-(n-k))*(n-k+1)/2;
	if(tmp-ans<=p) return 1;
	else return 0;
}
ll binary_find()
{
	ll l=0,r=p;
	ll ans=1;
	ll mid;
	while(l<=r)
	{		
		mid=(l+r)/2;	
		if(fun(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int main()
{
	while(cin >> n >> p >> k)
	{
		cout << binary_find()<<endl;
	}
}
