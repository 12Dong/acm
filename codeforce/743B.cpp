#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n,k;
	while(cin >> n >> k)
	{
		long long  len=pow(2,n)-1;
		long long mid=(1+len)/2;
		if(k>mid)
		{
			k=mid-abs(mid-k);
		}
		int cnt=0;
		while(k!=mid)
		{
			mid=(1+mid)/2;
			if(k>mid)
			{
				k=mid-abs(mid-k);
			}
			cnt++;
		}
		for(int i=cnt;i>0;i--)
		{
			n--;
		}

		cout << n <<endl;
	}
}
