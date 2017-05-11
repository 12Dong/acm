#include<iostream>
typedef long long ll;
using namespace std;
int main()
{
	ll n,a,b;
	while(cin >> n >> a >> b)
	{
		int w;
		for(ll i=0;i<n;i++)
		{
			cin >> w;
			if(i!=n-1) cout << ((w*a)%b)/a << " ";
			else cout << ((w*a)%b)/a <<endl;

		}
	}
 } 
