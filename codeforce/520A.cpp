#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool vis[26];
bool judge()
{
	for(int i=0;i<=25;i++)
	{
		if(vis[i]==0) return 0;
	}
	return 1;
}
int main()
{
	string str;
	int num;
	while(cin >> num)
	{
		cin >> str;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<str.size();i++)
		{
			if(str[i]>='A' && str[i]<='Z')
			{
				vis[str[i]-'A']=1;
			}
			else if(str[i]>='a' && str[i]<='z')
			{
				vis[str[i]-'a']=1;
			}
		}
		if(judge())
		{
			cout <<"YES"<<endl;
		}
		else 
		{
			cout <<"NO"<<endl;
		}
	}
}

