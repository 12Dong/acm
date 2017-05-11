#include<iostream>
using namespace std;
int main()
{
	int n;
	int k=1;
	while(cin >> n)
	{
 		cout << n <<endl;
		cout << "Times:"; 
		int ans=0;
		while(n!=0)
		{
			ans++;
			if(n<=3)
			break;
			else if(n%3==0)
			n=n/3;
			else 
			n=n/3+1;
			
		}
		
		cout << ans <<endl;
	}
}
