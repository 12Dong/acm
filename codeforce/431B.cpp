#include<iostream>
#include<algorithm>
using namespace std;
int pos[]={0,1,2,3,4,5};
long long ans;
int Matrix[10][10];
int main()
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			cin >> Matrix[i][j];
		}
	}
	long long ans=-1;
	do
	{
		long long tmp=0;
		for(int i=1;i<=5;i++)
		{
			for(int j=i;j<=5;j=j+2)
			{
				if(j!=5)
				tmp+=Matrix[pos[j]][pos[j+1]]+Matrix[pos[j+1]][pos[j]];

			}
		}
		ans=max(ans,tmp);
		
	}while(next_permutation(pos+1,pos+6));
	cout << ans <<endl;
}
