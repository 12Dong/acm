#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll ex_gcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		ll r=ex_gcd(b,a%b,x,y);
		ll t=x;
		x=y;
		y=t-a/b*y;
		return r;
	}
}
int main()
{
	ll a,b,c,k;
	while(cin >> a >> b >> c >> k)
	{
		if(a==0 && b==0 && c==0 && k==0) break;
		ll tmp=pow(2,k);
		ll x,y;
		ll d=ex_gcd(c,tmp,x,y);
		ll sum=b-a;
		if(sum%d!=0)
		{
			cout <<"FOREVER"<<endl;
			continue;
		}
		else
		{
			x*=(sum/d);
			ll r =tmp/d;
			cout << (x%r+r)%r <<endl;
		}
	}
}
