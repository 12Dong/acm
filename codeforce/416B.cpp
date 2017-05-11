#include<iostream>
#include<cstring>
#include<cmath>
typedef long long ll;
using namespace std;
#define N 50000+5
int num[N][12];
int sum[N][12];
int main()
{
	int n,m;
	while(cin >> n >> m)
	{
		int ans=0;
		memset(num,0,sizeof(num));
		memset(sum,0,sizeof(sum));
		int tmp;
		for(int i=0;i<n;i++)
		{
			int Sum=0;
			for(int j=0;j<m;j++)
			{
				if(i==0)
				{
					cin >> num[i][j];
					Sum+=num[i][j];	
					ans+=num[i][j];
				}	
				else
				{
					cin >> num[i][j];
					Sum+=num[i][j];
					if(j==m-1) 
					{
						ans+=num[i][j];
						continue;
					}
					sum[i][j]=sum[i-1][j]+tmp-num[i-1][j]-num[i][j];
					if(sum[i][j]<0) 
					{
						ans+=fabs(sum[i][j]);
						tmp-=fabs(sum[i][j]);
						sum[i][j]=0;
						
					}
					tmp-=num[i-1][j];
				}
			}
			tmp=Sum;
			if(i!=n-1) cout << ans <<" ";
			else cout << ans << endl;
		}
			
	}	
}
/*
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
901 801 701 601 501
*/
