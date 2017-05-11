#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
	string str;
	cin >> str;
	stack<int> s;
	int intStrblanks=0;
	for(int i=0;i<str.size();)
	{
		if(str[i]=='<' && str[i+1]!='/')
		{
//			cout << "intStrblanks="<<intStrblanks<<endl;
			s.push(intStrblanks);
			for(int j=1;j<=intStrblanks;j++)
			{
				cout <<" ";
			}
			cout <<str[i]<<str[i+1]<<str[i+2]<<endl;
			intStrblanks=intStrblanks+2;
			i=i+3;

		}
		else 
		{
			int intTmpblanks=s.top();
			s.pop();
			for(int j=1;j<=intTmpblanks;j++)
			{
				cout <<" ";
			}			
			cout <<str[i]<<str[i+1]<<str[i+2]<<str[i+3]<<endl;
			i=i+4;
			intStrblanks-=2;
		}
	}
}
