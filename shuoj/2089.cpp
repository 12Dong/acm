#include<iostream>
#include<cstring>
#include<string>
using namespace std;
struct Node
{
	int length;
	int num;
}seat[55];
int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		memset(seat,0,sizeof(seat));
		int len;
		cin >> len;
		string  str;
		cin >> str;
		int flag=0;
		int tmp=0;
		for(int i=0;i<len;i++)
		{
			if(str[i]=='P') continue;
			if(str[i]=='E' &&(str[i+1]=='E' || str[i-1]=='E'))
			{
				flag=1;
				seat[tmp++].num=i;
			}
		}
		if(flag==0) 
		{
			cout << -1 <<endl;
			continue;
		}
		int Max=-1;
		int ans;
		for(int i=0;i<tmp;i++)
		{
			seat[i].length=min(seat[i].num+1,len-seat[i].num);
			if(seat[i].length>Max)
			{
				Max=seat[i].length;
				ans=seat[i].num;
			}
		}
		cout << ans << endl;
		
		
		
	}
 } 
