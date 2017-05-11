#include<iostream>
using namespace std;
int num[100005];
int main()
{
	int n;
	while(cin >> n)
	{
		int cnt=0;
		int index=-1;
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		for(int i=0;i<n;i++)
		{
			if(num[i]>num[(i+1)%n])
			{
				cnt++;
				index=i;
			}
		}
		if(cnt==0)
		{
			cout << 0 << endl;
		}
		else if(cnt>=2)
		{
			cout << -1 << endl;
		}
		else
		{
			cout <<  n-index-1 << endl;
		}
	}
}
