#include<iostream>
using namespace std;
int num[35];
int fun(int n)
{
	if(num[n]) return num[n];
	else 
	{
		for(int i=n-2;i>=0;i=i-2)
		{
//			cout << i << endl;
			if(i!=n-2)
				num[n]=num[n]+2*fun(i);
			else 
			{
				num[n]=num[n]+3*fun(i);
			}
		}
		return num[n];
	}
}
int main()
{
	num[0]=1;
	num[2]=3;
	int n;
	while(cin >> n)
	{
		if(n==-1) 
		{
			break;
		}
		if(n%2==1)
		{
			cout << 0 << endl;
			continue;
		}
		cout << fun(n)<<endl;
	}
}
