#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str1,str2;
	while(cin >> str1 >> str2)
	{
		int suma=0,sumb=0;
		for(int i=0;i<str1.size();i++)
		{
			if(str1[i]>='A' && str1[i]<='Z')
			{
				str1[i]=str1[i]-'A'+'a';
			}
		}
		for(int i=0;i<str2.size();i++)
		{
			if(str2[i]>='A' && str2[i]<='Z')
			{
				str2[i]=str2[i]-'A'+'a';
			}
		}
		int flag=0;
		for(int i=0;i<str1.size();i++)
		{
			if(str1[i]==str2[i]) continue;
			else if(str1[i]>str2[i])
			{
				 cout <<1 <<endl;
				 flag=1;
				 break;
			}
			else
			{
				cout << -1 <<endl;
				flag=1;
				break;
			}
		}
		if(!flag) cout << 0 <<endl;
	}
 } 
