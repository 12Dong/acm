#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
// yr
const int N = 5*10000+5;
int num[N];
int vis[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	int n;
	while(cin >> n)
	{
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		sort(num,num+n);
		int cnt=0;
		for(int i=0;i<n;i++)
		{
			int l=0,r=n;
			int loc=-1;
			int mid;
			while(l<=r)
			{
				 
				mid=(l+r)/2;
//				if(i==0) cout << mid << endl;
				if(num[mid]>=2*num[i])
				{
					loc=mid;
					r=mid-1;
				}
				else 
				{
					l=mid+1;
				}
			}
			if(loc==-1) continue;
			else 
			{
				for(int j=mid;j<n;j++)
				{
					if(vis[mid]) continue;
					cnt++;
					vis[mid]=1;
					break;
				}
			}
			
		}
		cout << n-cnt << endl;
	}
}
