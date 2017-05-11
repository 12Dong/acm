#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{

	int n;
	while(cin >>n)
	{
		int t;
		int cnt=0;
		int result;
		for(int i=0;i<n;i++)
		{
			cin >>t;
			if(cnt==0)
			{
				result=t;
				cnt++;
			}
			else 
			{
				if(result==t) cnt++;
				else  cnt--;
			}
		}
		cout << result <<endl;
	}
	return 0;
}
