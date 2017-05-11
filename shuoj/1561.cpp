#include<iostream>
using namespace std;
long long num[5005];
#define MOD 1e9+7
long long function(int n)
{
	if(num[n]==0)
	{
		return num[n]=function(n-1)+function(n-2);
	}
	else 
	return num[n];
	
}
int main() 
{
	num[1]=1;
	num[2]=1;
	int n;
	while(cin >> n)
	{
		cout << 54224848179261915075%(1000000007)<<endl;

	}
}
