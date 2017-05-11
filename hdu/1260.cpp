#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	int single[2005];
	int Double[2005];
	int dp[2005];
	int n;
	cin >> n;
	while(n--)
	{
		memset(dp,0,sizeof(dp));
		int k;
		cin >> k;
		for(int i=0;i<k;i++)
		cin >> single[i];
		for(int i=0;i<k-1;i++)
		cin >>Double[i];
		for(int i=0;i<k;i++)
		{
			if(i==0) dp[i]=single[i];
			else if(i==1) dp[i]=min(dp[i-1]+single[i],Double[i-1]);
			else 
			{
				dp[i]=min(dp[i-1]+single[i],dp[i-2]+Double[i-1]);
			}
		}
	int ans=dp[k-1];
	int hours=ans/60/60;
	int minutes=(ans/60)%60;
	int seconds=ans%60;
	if(8+hours<12)
     printf("%02d:%02d:%02d am\n",8+hours,minutes,seconds);
    else 
     printf("%02d:%02d:%02d pm\n",8+hours-12,minutes,seconds);
}
}
