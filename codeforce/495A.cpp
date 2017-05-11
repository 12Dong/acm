#include<iostream>
#include<cstdio> 
using namespace std;
int num[11][11]=
{
	{0,8},
	{0,1,3,4,7,8,9},
	{0,2,8},
	{3,8,9},
	{4,8,9},
	{
		5,8,9
	},
	{
		6,8
	},
	{
		0,3,7,8,9
	},
	{
		8
	},
	{
		8,9
	}
};
int main()
{
	int n[11]={2,7,2,3,3,4,2,5,1,2};
	char str[3];
	scanf("%s",str);
	cout << n[str[0]-'0']*n[str[1]-'0']<< endl;
	
}
