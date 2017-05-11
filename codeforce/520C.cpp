#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const int MOD=1e9+7;
typedef long long ll;
ll T[5];
ll quick_multi(ll n,ll m)
{
	ll ans=1;
	ll tmp=n;
	while(m>0)
	{
		if(m&1)
		{
			ans=ans*tmp%MOD;
		}
		m/=2;
		tmp=tmp*tmp%MOD;
	}
	return ans;
}
int main()
{
	string str;
	int num;
	cin >> num;
	cin >> str;
	memset(T,0,sizeof(T)); 
	for(int i=0;i<num;i++)
	{
		if(str[i]=='A') T[0]++;
		else if(str[i]=='C') T[1]++;
		else if(str[i]=='T') T[2]++;
		else if(str[i]=='G') T[3]++;
	}
	ll times=0;
	ll Max=-1;
	for(int i=0;i<=3;i++)
	{
		if(T[i]>Max) 
		{
			Max=T[i];
			times=1;
		}
		else if(Max==T[i])
		{
			times++;
		}
	}
	cout << quick_multi(times,num);
}
