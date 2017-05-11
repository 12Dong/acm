#include<iostream>
#include<string>
#include<cstring>
using namespace std;
bool vis[1005];
int cnt1[26];
int cnt2[26];
int main()
{
	string str1,str2;
	while(cin >> str1 >> str2)
	{
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		for(int i=0;i<str1.size();i++)
		{
			cnt1[str1[i]-'a']++;
		}
		for(int i=0;i<str2.size();i++)
		{
			cnt2[str2[i]-'a']++;
		}
		int cnt=0;
		bool flag=1;
		for(int i=0;i<=25;i++)
		{
			if(cnt1[i]==0 && cnt2[i]!=0)
			flag=0;
			if(cnt1[i]>=cnt2[i]) cnt+=cnt2[i];
			else cnt+=cnt1[i];
		}
		if(flag==1)
		cout << cnt << endl;
		else 
		cout << -1 << endl;
	}
 } 
