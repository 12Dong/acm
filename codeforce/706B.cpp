#include<iostream>
#include<algorithm>
using namespace std;
int n;
const int N=100005;
int c[N];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			cin >> c[i];
		}
		sort(c,c+n,cmp);
		int q;
		cin >> q;
		for(int i=0;i<q;i++)
		{
			int mon;
			cin >> mon;
			int l=0,r=n;
			int ans=0;
			while(l<=r)
			{
//				cout << "***"<<ans << endl;
				int mid=(l+r)/2;
				if(c[mid]<=mon)
				{
					ans=mid;
					r=mid-1;
				}
				else l=mid+1;
			}
			cout << n-ans << endl;
		}
	}
 } 
