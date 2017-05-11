#include<iostream>
using namespace std;
//yrrrrrrrrrr
int main()
{
	int num;
	while(cin >> num)
	{
		int have=0;
		int cur;
		int ans=0;
		for(int i=0;i<num;i++)
		{
			cin >> cur;
			if(cur>0) have+=cur;
			else 
			{
				if(cur+have>=0) have--;
				else ans++;
			}
		}
		cout << ans << endl;
	}
}
