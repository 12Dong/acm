#include<iostream>
using namespace std;
//yr
int ex_gcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		int r=ex_gcd(b,a%b,x,y);
		int tmp=x;
		x=y;
		y=tmp-a/b*y;
		return r;
	}
}
int main()
{
	int a,b,m;
	while(cin >> a >> b >> m)
	{
		int x,y;
		int r=ex_gcd(a,m,x,y);
//		cout <<r  <<endl;
		if(b%r!=0)
		{
			cout << "no solutions!"<<endl;
		}
		else
		{
			int c=b/r;
			x=x*c;
			int k=m/r;
			cout << (x%k+k)%k << endl;
		}
	}
}
