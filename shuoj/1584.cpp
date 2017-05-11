#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
	long long n;
	long long ans;
	while(cin >> n)
	{
		ans=(pow(n,6)*5+pow(n,10)+pow(n,2)*4)/10;
		cout << ans <<endl;
	}
}
