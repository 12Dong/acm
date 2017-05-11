#include<iostream>
using namespace std;
typedef long long ll;
ll gcd(ll a,ll b)
{
	if(b!=0) return gcd(b,a%b);
	else return a;
}
ll  exgcd(ll a,ll b,ll &x,ll &y)
{
	if(b==0) 
	{
		x=1;
		y=0;
//		cout << "x=" <<x << " "<<"y="<<y <<" "<< a<<endl;;
		return a;
	}
	ll r=exgcd(b,a%b,x,y);
	ll t=x;
	x=y;
	y=t-a/b*y;
//	cout << "x=" <<x << " "<<"y="<<y <<" "<< r<<endl;
	return r;
}
int main()
{
	ll a,b;
	while(cin >> a >> b)
	{
		ll x,y;
		if(gcd(a,b)!=1)
		{
			cout <<"sorry"<<endl;
//			cout << gcd (a,b)<<endl;
			continue;
		}
		else 
		{
			exgcd(a,b,x,y);
      	    while (x < 0) 
			{
     	       x += b, y -= a;
    	    }
			cout << x <<" "<<y<<endl;
			
		
		}
	
	}
}
