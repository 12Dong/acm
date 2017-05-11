#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
int main()
{
	ll a,b;
	while(cin  >> a >> b)
	{
		if(a==b)
		{
			cout <<"infinity"<<endl;
			continue;
		}
		ll tmp=a-b;
		ll cnt=0;
		for(ll i=1;i<=sqrt(tmp);i++)
		{
			if(tmp%i==0)
			{
				if(i!=tmp/i)
				{
					if(i>b) cnt++;
					if(tmp/i>b) cnt++;
				}
				else
				{
					if(i>b) cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
}
