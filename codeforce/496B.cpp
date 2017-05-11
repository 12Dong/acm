#include<iostream>
#include<string>
using namespace std;
int n;
string fun1(string str)
{
//	cout << "fun1"<<endl;
	for(int i=0;i<n;i++)
	{
		str[i]=(str[i]-'0'+1)%10+'0';
	}
//	cout << str << endl;
	return str;
}
string fun2(string str)
{
//	cout << "fun2"<<endl;
	string ans=str;
	ans[0]=str[n-1];
	for(int i=0;i<n-1;i++)
	{
		ans[i+1]=str[i];
	 } 
//	 cout << ans << endl;
	 
	 return ans;
}
int main()
{
	while(cin >> n)
	{
		string str;
		cin >> str;
		string ans=str;
		for(int i=0;i<=n;i++)
		{
			str=fun2(str);
			for(int j=0;j<10;j++)
			{
				str=fun1(str);
				if(str<ans)
				ans=str;
			}
		}
		cout << ans << endl;
	}
}
