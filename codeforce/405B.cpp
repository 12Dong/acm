#include<iostream>
#include<string> 
using namespace std;
int main()
{
	int n;
	while(cin >> n)
	{
		string str;
		cin >> str;
		bool flagF=0;
		bool flagE=0;
		int cnt=0;
		int len=0;
		int lastd=-1;
		int firsd=-1;
		for(int i=0;i<n;i++)
		{
//			cout << cnt <<"  " << len <<  endl;
			if(str[i]!='.' && firsd==-1) firsd=i;
			if(str[i]!='.') lastd=i;
			if(str[i]=='R')
			{
				len++;
			}
			else if(str[i]=='L')
			{
				if(len) 
				{
					len--;
					if(len%2!=0) cnt++;
					len=0;
				}
			}
			else if(str[i]=='.')
			{
				if(firsd==-1) continue;
				else 
				{
					if(str[lastd]!='R')
						cnt++;
					else 
						len++;
				}
			}
			
		}
		if(str[firsd]=='R') cnt+=firsd;
		if(lastd==-1) cnt=n;
		cout << cnt << endl;
		

	}
}
