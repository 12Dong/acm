#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		int ans=1;
		int a=8;
		while(n>0)
		{
			if(n&1)
			{
				ans=ans*a%10;
			}
			n>>=1;
			a=a*a%10;
		}
		cout << ans<<endl;
	}
}
