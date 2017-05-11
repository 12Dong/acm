#include<stdio.h>
#include<math.h>
long long power(long long n,int x)
{
	long long ans=1;
	for(int i=1;i<=x;i++)
	ans*=n;
	return ans;
}
int main()
{
	long long n;
	while(scanf("%lld",&n)==1)
	{
		if(n==0) break;
//      ans=Cal(n,6)+3*Cal(n,4)+12*Cal(n,3)+8*Cal(n,2); 
		long long ans=(power(n,6)*1+power(n,4)*3+power(n,3)*12+power(n,2)*8)/24;
		printf("%lld\n",ans);
	}
 } 
