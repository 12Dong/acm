#include<iostream>
using namespace std;
int time[105];
int people[105];
int main()
{
	int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> people[i];
			time[i]=people[i]*15;
		}
		int item;
		int Min=0x3f3f3f3f;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<people[i];j++)
			{
				cin >> item ;
				time[i]+=item*5;
			}
			Min=min(Min,time[i]);
			
		}
		cout << Min << endl;
	}
}
