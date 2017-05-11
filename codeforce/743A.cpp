#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
	int n,s,e;
	while(cin >> n >> s >> e)
	{
		string str;
		cin >> str;
		s--,e--;
		if(str[s]==str[e]) cout <<  0 <<endl;
		else cout << 1 <<endl;
		}
		
	}
