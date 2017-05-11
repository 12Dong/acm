#include<iostream>
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		int tmp=n%3;
		n=n/3;
		if(tmp==2) n++;
		int feet=n/12;
		int inch=n-feet*12;
		cout << feet <<" " <<inch <<endl; 
	}
}
