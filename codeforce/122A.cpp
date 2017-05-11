#include<iostream>
using namespace std;
bool judge(int n)
{
	while(n!=0)
	{
		int tmp=n%10;
		if(tmp!=4 && tmp!=7) return false;
		n=n/10;
	}
	return true;
}
int num[1000];
int len=0;
void function()
{
	for(int i=1;i<=1000;i++)
	{
		if(judge(i))
		{
			num[len++]=i;
		}
	}
}
int main()
{
	function();
	int n;
	while(cin >> n)
	{
		int flag=0;
		for(int i=0;i<len;i++)
		{
			if(n%num[i]==0) 
			{
				flag=1;
				cout << "YES"<<endl;
				break;
			}
		}
		if(flag==0)
		cout << "NO"<<endl;
	}
}
