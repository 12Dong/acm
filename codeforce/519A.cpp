#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	int sumw=0,sumb=0;
	for(int i=0;i<8;i++)
	{
		cin >> str;
		for(int i=0;i<str.size();i++)
		{
			char c=str[i];
			if(c=='Q') sumw+=9;
			else if(c=='R') sumw+=5;
			else if(c=='B') sumw+=3;
			else if(c=='N') sumw+=3;
			else if(c=='P') sumw+=1;
			else if(c=='q') sumb+=9;
			else if(c=='r') sumb+=5;
			else if(c=='b') sumb+=3;
			else if(c=='n') sumb+=3;
			else if(c=='p') sumb+=1;
		}
	}
	if(sumb==sumw) cout <<"Draw" <<endl;
	else if(sumb>sumw) cout <<"Black"<<endl;
	else if(sumb<sumw) cout <<"White"<<endl;

}
