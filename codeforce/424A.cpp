#include<iostream>
#include<string>
using namespace std;
//yr
int main()
{
	string str;
	int len;
	while(cin >> len)
	{
		cin >> str;
		int X=0;
		int x=0;
		for(int i=0;i<len;i++)
		{
			if(str[i]=='x') x++;
			else X++;
		}
		if(x==X)
		{
			cout << 0 << endl;
			cout << str << endl;
		}
		else if (x>X)
		{
			
			int need=(x-X)/2;
			cout << need << endl;
			int cur=0;
			for(int i=0;i<len;i++)
			{
				if(str[i]=='x')
				{
					if(cur<need)
					{
						cout <<'X';
						cur++;
					}
					else
					{
						cout << str[i];
					}
				}
				else
				{
					cout << str[i];
				}
			}
			cout <<endl;
		}
		else if (X>x)
		{
			int need=(X-x)/2;
			cout << need << endl;
			
			int cur=0;
			for(int i=0;i<len;i++)
			{
				if(str[i]=='X')
				{
					if(cur<need)
					{
						cout <<'x';
						cur++;
					}
					else
					{
						cout << str[i];
					}
				}
				else
				{
					cout << str[i];
				}
			}
			cout <<endl;
		}
	}
}
