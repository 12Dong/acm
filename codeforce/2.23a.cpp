#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a,b;
	while(cin >> a >> b)
	{
		int num;
		cin >> num;
		string c=a,d=b;
		string ans1,ans2;
		for(int i=1;i<=num;i++)
		{
			cout <<"  " << c << " "<<d<<endl;
			cin >> a >> b;
			if(c==a) c=b;
			else d=b;
		}
		cout << c << " "<<d<<endl;
	}
}
