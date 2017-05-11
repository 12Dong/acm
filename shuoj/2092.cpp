#include<iostream>
#include<stack>
#include<queue> 
#include<string>
using namespace std;
int main()
{
	stack<char> s1;
	stack<int> s2;
	string str;
	while(cin >> str)
	{
		int i;
		cout << str.size()<<endl;
		while(i<str.size())
		{
			cout << i << endl;
			if(str[i]=='1' && str[i+1]=='0')
			{
				s2.push(10);
				i=i+2;
			}
			else if(str[i]=='A')
			{
				s2.push(1);
				i++;
			}
			else if(str[i]=='J')
			{
				s2.push(11);
				i++;
			}	
			else if(str[i]=='Q')
			{
				s2.push(12);
				i++;
			}		
			else if(str[i]=='K')
			{
				s2.push(13);
				i++;
			}
			else if(str[i]>='2' && str[i]<='9')
			{
				s2.push(str[i]-'0');
				i++;
			}		
			else if(str[i]=='+' || str[i]=='-')
			{
				s1.push(str[i]);
				i++;	
			}	
			else if(str[i]=='*')
			{
				if(s1.top()=='+' || s1.top()=='-' || s1.top()=='(')
				{
					int num1=s2.top();
					s2.pop();
					int num2=s2.top();
					s2.pop();
					num1=num1*num2;
					s2.push(num1);
				}
				else
				{
					s1.push(str[i]);

				}
				i++;
			}
			else if(str[i]=='/')
			{
				if(s1.top()=='+' || s1.top()=='-' || s1.top()=='(')
				{
					int num1=s2.top();
					s2.pop();
					int num2=s2.top();
					s2.pop();
					num1=num1/num2;
					s2.push(num1);
				}
				else
				{
					s1.push(str[i]);
				}
				i++;
			}
			else if(str[i]=='(')
			{
				s1.push(str[i]);
				i++;
			}
			else if(str[i]==')')
			{
				while(s1.top()!='(')
				{
					char tmp=s1.top();
					if(tmp=='+')
					{
						int num1=s2.top();
						s2.pop();
						int num2=s2.top();
						s2.pop();
						s2.push(num1+num2);	
					}
					else if(tmp=='-')
					{
						int num1=s2.top();
						s2.pop();
						int num2=s2.top();
						s2.pop();
						s2.push(num1-num2);	
					}
					s1.pop();					
				}
				i++;
				cout << s1.top()<<endl;
				s1.pop();
			}
		}
		cout <<"OK"<<endl;
		while(!s1.empty())
		{
			char tmp=s1.top();
			cout << tmp << endl;
			s1.pop();
			if(tmp=='+')
			{
				int num1=s2.top();
				s2.pop();
				int num2=s2.top();
				s2.pop();
				s2.push(num1+num2);
			}
			else if(tmp=='-')
			{
				int num1=s2.top();
				s2.pop();
				int num2=s2.top();
				s2.pop();
				s2.push(num1-num2);				
			}
			else if(tmp=='*')
			{
				int num1=s2.top();
				s2.pop();
				int num2=s2.top();
				s2.pop();
				s2.push(num1*num2);				
			}
			else if(tmp=='/')
			{
				int num1=s2.top();
				s2.pop();
				int num2=s2.top();
				s2.pop();
				s2.push(num1/num2);				
			}
		}
		int ans=s1.top();
		if(ans==24)
		{
			cout << "YES"<<endl;
		}
		else
		{
			cout <<"NO"<<endl;
		}
	}
}


