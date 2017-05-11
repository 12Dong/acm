#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define N 2000000000LL
ll len=0;
ll a[200005]={0};
void dfs(long long n)
{
	if(n)
	{
		a[++len]=n;
	}
	if(n<=N)
	{
		dfs(n*10+4);
		dfs(n*10+7);
	}
}
int main()
{
	ll l,r;
	dfs(0);
	sort(a+1,a+len+1);
	cin >> l >> r;
	ll left=0;
	ll right;
	ll ans=0;
	for(left=1;a[left]<l;left++);
	for(right=1;a[right]<r;right++);
	if(left==right)
	{
		cout << a[left]*(r-l+1)<<endl;
	}
	else 
	{
		for(int i=left+1;i<=right-1;i++)
		{
			ans+=a[i]*(a[i]-a[i-1]);
		}
		ans+=(a[left]-l+1)*a[left];
		ans+=(r-a[right-1])*a[right];
		cout << ans <<endl;
	}
}
