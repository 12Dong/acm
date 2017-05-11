#include<iostream>
using namespace std;
int main()
{
	int n;
	int num[110];
	int dif[110];
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
			if(i>0)
			{
				dif[i]=num[i]-num[i-1];
			}
		}
		int Min=0x3f3f3f3f;
		for(int i=1;i<n-1;i++)
		{
			int Max=-1;
			for(int j=1;j<n;j++)
			{
				if(j!=i)
					Max=max(Max,dif[j]);
				else 
				{
					int tmp=dif[i]+dif[i+1];
					Max=max(Max,tmp);
				}
			}
			Min=min(Min,Max);
		}
		cout << Min << endl;
	}

}
