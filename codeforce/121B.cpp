#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		string str;
		cin >> str;
		while(k--)
		{
			int loc=-1;
			int i;
			for(i=0;i<n;i++)
			{
				if(str[i]=='4' && str[i+1]=='7')
				{
					loc=i;
					break;
				}
			}
			if(loc==-1) break;
			else 
			{
//				cout << loc << endl;
				if(loc%2==0)
				{
					str[loc]='4';
					str[loc+1]='4';
				}
				else 
				{
					str[loc]='7';
					str[loc+1]='7';
				}
			}
			
		}
		cout << str <<endl;
	}
}
