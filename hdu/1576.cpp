#include<iostream>
using namespace std;
int main()
{
	long long n,b;
	while(cin >> n >> b)
	{
		b=b%9973;
		cout << (n+9973)/b <<endl; 
	}
}
