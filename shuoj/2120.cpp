#include<iostream>
using namespace std;
//yr
int num[1000]={0,0,1,1,2,3};
int getnum(int i)
{
	if(num[i]!=0) return num[i];
	else return num[i]=getnum(i-1)+getnum(i-2);
}

int main()
{
	int a,n,m,x;
	while(cin >> a >> n >> m >> x)
	{
		int y=(m-(getnum(n-2)+1)*a)/(getnum(n-1)-1);
		cout << (getnum(x)-1)*y+(getnum(x-1)+1)*a << endl;
	}
}
