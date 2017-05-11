#include<iostream>
#include<cstring> 
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int ans[1015][1015];
int str[10005];
ll n,k,d;
void spilt(ll mem)
{
	for(int i=0;i<d;i++)
	{
		ans[mem][i]=str[i];
	}
	str[d-1]++;
	for(int i=d-1;i>=0;i--)
	{
		if(i!=0)
		{
			if(str[i]>k)
			{
				str[i-1]++;
				str[i]=1;
			}			
		}
		else
		{
			if(str[i]>k)
			{
				str[i]=1;
			}
		}
	}
//	cout << ANS <<endl;
//	cout << "END"<<endl;
}
int main()
{
	while(cin >> n >> k >> d)
	{
		ll power=1;
		bool judge=0;
		for(ll i=1;i<=d;i++)
		{
			power*=k;
			if(power>=n)
			{
				judge=1;
				break;
			}
		}
		if(!judge)
		{
			cout << -1 << endl;
			continue;
		}
		memset(ans,0,sizeof(ans));
		ll cnt=0;
		while(cnt<=d)
		{
			str[cnt++]=1;
		}
//		cout <<str << endl;
//		cout <<Ans << endl;
		for(int i=0;i<n;i++)
		{
//			cout << str << endl;
//			cout << Ans << "**"<<endl;
			spilt(i);
		}
//		cout << " 2222"<<endl;
		for(int j=0;j<d;j++)
		{
			for(int i=0;i<n;i++)
			{
				if(i!=n-1)
				{
					cout << ans[i][j]<<" ";
				}
				else
				{
					cout << ans[i][j]<<endl;
				}
			}
		}
	}
}
