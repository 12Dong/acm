#include<iostream>
#include<string>
#include<cstdio>
#include<stdio.h>
using namespace std;
int main()
{
	string str;
	int rail;
	freopen("input.txt","r",stdin);
	cin >> str >> rail;
		if(rail==1)
		{
			if(str[0]=='f')
			{
				freopen("output.txt","w",stdout);
				cout << "L"<<endl;
			}
			else 
			{
				freopen("output.txt","w",stdout);
				cout << "R"<<endl;
			}
		}
		else if(rail==2)
		{
			if(str[0]=='f')
			{
				freopen("output.txt","w",stdout);
				cout << "R"<<endl;
			}
			else 
			{
				freopen("output.txt","w",stdout);
				cout << "L"<<endl;
			}
		}
	
}
