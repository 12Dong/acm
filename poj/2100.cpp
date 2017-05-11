#include<iostream>
#include<cmath>
typedef long long ll;
using namespace std;
ll Ans[10000005][2];
int main()
{
	ll n;
	while(cin >> n)
	{
		ll times;
		ll l=1,r=1;
		ll el,er;
		ll ans=0;
		ll sum=0;
		while(1)
		{
			while(r<=sqrt(n)&& sum < n)
			{
				sum=sum+r*r;
				r++;
			}
			if(sum < n) break;
			if(sum==n) 
			{
				Ans[ans][0]=l;
				Ans[ans++][1]=r;
			}
			sum=sum-l*l;
			l++;
		}
		cout << ans <<endl;
		for(ll i=0;i<ans;i++)
		{
			cout << Ans[i][1]-Ans[i][0]<<" ";
			for(ll j=Ans[i][0];j<Ans[i][1];j++)
			{
				j==Ans[i][1]-1?cout <<j<<endl:cout <<j<<" ";
			}
		}
	}
}
