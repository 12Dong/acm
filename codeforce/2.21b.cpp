#include<iostream>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
int num1[4];
int num2[100];
int num3[110];
int main()
{
	long long n,l,r;
	while(cin >> n >> l>> r)
	{
		int k=0;
		bool flag=true;
		while(n!=1)
		{
			num2[k++]=n%2;
			if(n%2==1)
			flag=true;
			else 
			flag=false;
			n=n/2;
			if(n==1)
			{
				if(flag)
				{
					num1[1]=1;
			     	num1[2]=1;
			    	num1[3]=1;
				}
				else 
				{
					num1[1]=1;
					num1[2]=0;
					num1[3]=1;
				}
			}

	  }
	  int s=pow(2,k);
	  int sum=num1[0]+num1[1]+num1[2];
	  for(int i=0;i<k;i++)
	  {
	  	num3[i]=num2[k-1-i];
	  }
//	  cout << s <<endl;
//	  cout << k <<endl;
	  if(r<=s)
	  {
	  	long long  ans=0;
	  	for(int i=l;i<=r;i++)
	  	{
	  		if(l%4==0) ans+=num3[l/4-1 ];
	  		else ans+=num1[l%4];
		  }
		  cout << ans << endl;
	  }
	  else if(l>=s)
	  {
	  	if(l==s)
	  	{
	  			  	int tmp1=(r-l+1)/4;
//	  	cout << tmp1 <<endl;
	  	int tmp2=(r-l+1)%4;
//	  	cout << tmp2 <<endl;
	  	int ans1=tmp1*sum;
//	  	cout << ans1 <<endl;
	  	int ans2=0;
	  	for(int i=0;i<tmp2;i++)
	  	ans2+=num1[i];
//	  	cout << ans2 <<endl;
	  	int ans3=0;
	  	for(int i=1;i<=tmp1;i++)
	  	{
	  		ans3+=num2[k-i-1];
		  }
//		  cout << ans3 <<endl;
		cout << ans1+ans2+ans3<<endl;
		  }
		  else
		  {
		  		  	int tmp1=(r-l)/4;
//	  	cout << tmp1 <<endl;
	  	int tmp2=(r-l+1)%4;
//	  	cout << tmp2 <<endl;
	  	int ans1=tmp1*sum;
//	  	cout << ans1 <<endl;
	  	int ans2=0;
	  	for(int i=0;i<tmp2;i++)
	  	ans2+=num1[i];
//	  	cout << ans2 <<endl;
	  	int ans3=0;
	  	for(int i=1;i<=tmp1;i++)
	  	{
	  		ans3+=num2[k-i-1];
		  }
//		  cout << ans3 <<endl;
		cout << ans1+ans2+ans3+num2[0]<<endl;
		  }
	  }
	  else 
	  {
	  	int tmp1=(s-l)/4;
	  	int tmp2=(s-l)%4;
	  	int ans1=tmp1*sum;
//	  	cout << ans1 <<endl;
	  	int ans2=0;
	  	for(int i=0;i<tmp2;i++)
	  	ans2+=num1[i];
//	  	cout << ans2 <<endl;
	  	int ans3=0;
	  	for(int i=1;i<=tmp1;i++)
	  	{
	  		ans3+=num2[k-i-1];
		  }	  	
//		  cout << ans3 <<endl;
		int ans4=ans1+ans2+ans3;
//		cout <<  ans4 <<endl;
//		cout << "************"<<endl;
		tmp1=(r-s)/4;
//		cout << tmp1<<endl;
		tmp2=(r-s)%4;
//		cout << tmp2<<endl;
		ans1=tmp1*sum;
//		cout << ans1 <<endl;
		ans2=0;
	  	for(int i=0;i<tmp2;i++)
	  	ans2+=num1[i];
//	  	cout << ans2 <<endl;
	  	ans3=0;
	  	for(int i=1;i<=tmp1;i++)
	  	{
	  		ans3+=num2[k-i-1];
		  }	 
//		  cout << ans3 <<endl;
		 ans4=ans4+ans1+ans2+ans3+num2[0];		
		 cout << ans4 <<endl;
	  }
		
	}
}
