#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
const int Mod=1000000443;
ll quick_mat(ll a,ll b)
{
	ll ans=1;
	while(b>0)
	{
		if(b&1)
		{
			ans=(ans*a)%Mod;
		}
		b>>=1;
		a=(a*a)%Mod;
	}
	return ans;
}
int main()
{
	ll num[10005];
	string str;
	for(int i=1;i<=10000;i++)
	{
		num[i]=quick_mat(i,i);
	}
	while(cin >> str)
	{
		ll r=0;
		for(int i=0;i<str.size();i++)
		{
			r=(r*10+str[i]-'0')%Mod;
		}
		ll flag=-1;
		for(int i=1;i<=10000;i++)
		{
			if(num[i]==r)
			{
				flag=i;
				break;
			}
		}
		if(flag==-1) cout <<"NO"<<endl;
		else cout << flag <<endl;
	}
}
