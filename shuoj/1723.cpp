#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int num[11000];
	int n,m;
	while(cin >> n >> m)
	{
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		sort(num,num+n);
		int s=num[0];
		int cnt=1;
		for(int i=1;i<n;i++)
		{
			if(num[i]>s+m)
			{
				cnt++;
				s=num[i];
			}
		}
		cout << cnt <<endl;
	}
}
