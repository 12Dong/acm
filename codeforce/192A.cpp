#include<iostream>
#include<cmath> 
using namespace std;
//yr
int main()
{
	int num;
	while(cin >> num)
	{

//		±©Á¦Ã¶¾Ù³¬Ê±
//		938938476 
		bool flag=0;
		for(int a=1;a<sqrt(num);a++)
		{
			if(flag) break;
			int res=2*num-(a*a+a);
			int l=0,r=sqrt(res);
			while(l<=r)
			{
				if(flag) break;
				int mid=(l+r)/2;
				if(mid*(mid+1)/2>res)
				{
					r=mid-1;
				}
				else if(mid*(mid+1)==res) 
				{
					flag=1;
				}
				else
				{
					l=mid+1;
				}
			}
		}
		if(flag) cout << "YES"<<endl;
		else cout <<"NO"<<endl;
	}
}
