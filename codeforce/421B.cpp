#include<iostream>
#include<string>
using namespace std;
//yr


bool vis[26]={1,0,0,0,0,0,0,1,1,0,0,0,1,0,1,0,0,0,0,1,1,1,1,1,1,0};

string b; 
int main()
{
	string a;
	while(cin >> a)
	{
		bool flag=1;
		for(int i=0;i<a.size();i++)
		{
			if(!vis[a[i]-'A'])
			{
				flag=0;
				break;
			}
		}
		if(flag==0)
		{
			cout <<"NO"<<endl;
			break;
		}
		int len=0;
		for(int i=a.size()-1;i>=0;i--)
		{
			b+=a[i];
		}
//		cout << b << endl;
		if(a==b)
		{
			cout <<"YES"<<endl;
		}
		else 
		{
			cout <<"NO"<<endl;
		}
	}
}
