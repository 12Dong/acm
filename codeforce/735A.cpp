#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n,k;
	while(cin >> n >> k)
	{
		string str;
		cin >> str;
		int s,e;
		for(int i=0;i<n;i++)
		{
			if(str[i]=='G') s=i;
			else if(str[i]=='T') e=i;
		}
		if(s<e)
		{
			int cur=s;
			int flag=0;
			while(cur<=e)
			{
				if(str[cur]=='#') 
				{
					flag=1;
					cout <<"NO"<<endl;
					break;
				}
				else if(str[cur]=='T') 
				{
					cout <<"YES"<<endl;
					flag=1;
					break;
				}
				else 
				{
					cur+=k;
				}
			}
			if(!flag) cout <<"NO"<<endl;
		}
		else 
		{
			int cur=s;
			int flag=0;
			while(cur>=e)
			{
				if(str[cur]=='#') 
				{
					flag=1;
					cout <<"NO"<<endl;
					break;
				}
				else if(str[cur]=='T') 
				{
					cout <<"YES"<<endl;
					flag=1;
					break;
				}
				else 
				{
					cur-=k;
				}
			}
			if(!flag) cout <<"NO"<<endl;			
		}
	}
}
