#include<iostream>
#include<algorithm>
using namespace std;
//yr
#define  INF 0x3f3f3f3f
typedef long long ll;
ll num[200005];
int main()
{
	ll n;
	while(cin >> n)
	{
		ll cnt=0;
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		sort(num,num+n);
		ll Minnum=0;
		ll Maxnum=0;
		ll Min=num[0];
		ll Max=num[n-1];
		for(int i=0;i<n;i++)
		{
			if(num[i]==Min) Minnum++;
			else break;
		}
		for(int i=n-1;i>=0;i--)
		{
			if(num[i]==Max) Maxnum++;
			else break;
		}
		cout << Max-Min <<" ";
		if(Max==Min) cout << Maxnum*(Maxnum-1)/2<<endl;
		else cout << Maxnum*Minnum<<endl;
	}
	
}
