/*
#include<iostream>
#include<string>
using namespace std;
string str;
void function(int x)
{
	for(int i=x;i<str.size()-1;i++)
	{
		str[i]=str[i+1];
	}
}
int main()
{

	int n;
	cin >> n;
	
	while(n--)
	{
		int num;
		cin >> str;
		int len=str.size();
		cin >> num;
		int tmp=num;
		while(num--)
		{
			for(int i=0;i<str.size();i++)
			{
				if(str[i]>str[i+1])
				{
//					cout << str[i]<<endl;
					function(i);
					break;
				}
				
				
			}
//			cout << str<<endl;
		}
		int i=0;
		while(str[i]=='0')
		{
			i++;
		}
		if(i>len-tmp)
		{
			cout << 0  <<endl;
		}
		else 
		{
		for(int j=i;j<i+len-tmp;j++)
		cout << str[j];
		cout <<endl;
		}
	}
}

*/
#include<iostream>
#include<cstring>
using namespace std;
 
int main()
{
	int num;
	cin >> num;
	while(num--)
{
   string STR;
   cin>>STR;
     STR+='e';         //????
     int N;
     cin>>N;
     int cnt=0;
     int i=0;
     while(cnt<N)
     {
         if(STR[i]>STR[i+1])    
         {
              STR.erase(i,1);
              cnt++;
              i=-1;  
         }
         if(STR[i]=='e')
         {
              STR.erase(i-1,1);    //???? ??????
              cnt++;
              i=-1;  //?????
         }
         i++;
     }
     STR=STR.substr(0,STR.length()-1);    
     int k=0;       
     while(STR[k]=='0')
         k++;
     STR=STR.substr(k,STR.length()-k);
     if(!STR.length())     
         cout<<'0' <<endl;             
     else
         cout<<STR<<endl;
         
}
     return 0;
}

