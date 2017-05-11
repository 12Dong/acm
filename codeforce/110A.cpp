#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while(cin >>str)
	{
		int num=0;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='4' || str[i]=='7')
			{
				num++;
			}
		}
		if(num==4 || num==7)
		{
			cout <<"YES"<<endl;
		}
		else 
		cout <<"NO"<<endl;
	}
}
