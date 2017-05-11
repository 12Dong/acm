#include<iostream>
using namespace std;
int num[300005];
int main()
{
	int n,times;
	while(cin >> n >> times)
	{
		for(int i=0;i<n;i++)
		{
			cin >> num[i];
		}
		int l=0,r=0;
		int el,er;
		int ans=-1;
		int cur=0;
		
		while(r<n)
		{

			while(cur<=times && r<n)
			{
				if(num[r]==0)
				{
					if(cur==times) break;
					else cur++;
				}
				r++;	
			}
			if(r-l>ans)
			{
//				cout << l << "   "<<r<<endl;
				el=l;
				er=r-1;
				ans=er-el+1;
			}
			while(cur>=times && l<=r )
			{
				if(num[l]==0)
					if(cur==times)
						cur--;
				l++;
			}
		}
		
		cout << ans  <<endl;
		for(int i=0;i<el;i++)
		{
			i==n-1?cout << num[i]:cout << num[i] <<" ";
		}
		for(int i=el;i<=er;i++)
		{
			i==n-1?cout << 1 :cout << 1 <<" ";
		}
		for(int i=er+1;i<n;i++)
		{
			i==n-1?cout << num[i]:cout << num[i] <<" ";
		}
		
	}
}
