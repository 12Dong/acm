#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	int k=1;
	while(cin >> n)
	{
		string str;
		long long ans=-1;
		for(int i=0;i<n;i++)
		{
			cin >> str;
			long long tmp=0;
			for(int j=0;j<str.size();j++)
			{
				tmp+=(long long)str[j];
			}
			ans=max(ans,tmp);
		}
		printf("Case %d: %lld\n",k++,ans);
	}
}
