#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
int main()
{
	char str[110];
	while(scanf("%s",str)!=EOF)
	{
		stack <char> s;
		int flag=0;
		for(int i=0;i<strlen(str);i++)
		{
			
			if(str[i]=='{' ||str[i]=='(' ||str[i]=='[' )
			{
				s.push(str[i]);
			}
			else if(str[i]==')')
			{
				if(s.empty())
				{
					flag=1;
					break;
				}
				else if(s.top()=='(')
				{
					s.pop();
				}
				else 
				{
					flag=1;
					break;
				}
			}
			else if(str[i]=='}')
			{
				if(s.empty())
				{
					flag=1;
					break;
				}
				else if(s.top()=='{')
				{
					s.pop();
				}
				else 
				{
					flag=1;
					break;
				}
			}
			else if(str[i]==']')
			{
				if(s.empty())
				{
					flag=1;
					break;
				}				
				else if(s.top()=='[')
				{
					s.pop();
				}
				else 
				{
					flag=1;
					break;
				}
			}
		}
		if(!s.empty()) flag=1;
		if(flag==1) cout <<"NO"<<endl;
		else cout <<"YES"<<endl;
	}
 } 
