#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int num[110];
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		sort(num,num+n);
		for(int i=0;i<n;i++)
		{
			if(i!=n-1)
			{
				cout << num[i]<<" ";
			}
			else 
			{
				cout <<num[i] << endl;
			}
		}
	}
}
