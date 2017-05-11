#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//yr
string str[25];
bool cmp(string a,string b)
{
	int len1=a.size();
	int len2=b.size();
	int len=max(len1,len2);
	for(int i=0;i<len;i++)
	{
		if(a[i%len1]!=b[i%len2])
			return a[i%len1]>b[i%len2];
			
	}
	return 0;
}
int main()
{
	int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> str[i];
		}
		sort(str,str+n,cmp);
		for(int i=0;i<n;i++)
		{
			cout << str[i];
		}
		cout << endl;
	}
		
}
