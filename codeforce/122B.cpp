#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while(cin >> str)
	{
		int flag4=0;
		int loc4=-1;
		int flag7=0;
		int loc7=-1;
		for(int i=0;i<str.size();i++)
		{
			if(str[i]=='4')
			{
				if(loc4==-1)
				{
					loc4=i;
				}
				flag4++;
			 } 
			else if(str[i]=='7')
			{
				if(loc7==-1)
				{
					loc7=i;
				}
				flag7++;
			}
		}
		if(flag4>flag7) cout << 4 <<endl;
		else if(flag7>flag4) cout << 7 <<endl;
		else if(flag4==0 && flag7==0)
		{
			cout << -1 <<endl;
		}
		else {
			cout << 4 <<endl;
		}

	}
}
