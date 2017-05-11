#include<iostream>
#include<string>
#include<cstring>
using namespace std;
char c[20][20];
char ans[20][20];
bool vis[20];
int main()
{
	string str;
	string str2;
	while(cin >> str)
	{
		if(str=="THEEND") break;
		cin >> str2;
		memset(c,0,sizeof(c));
		memset(ans,0,sizeof(ans));
		memset(vis,0,sizeof(vis));
		int len=str.size();
		int len2=str2.size();
//		cout << len <<" "<<len2<<endl;
		int row=0,col=0;
		int Maxrow=len2/len;
		for(int i=0;i<len2;i++)
		{
			c[row++][col]=str2[i];
			if(row==Maxrow) col++;
			row=row%Maxrow;
			
		}
//		for(int i=0;i<Maxrow;i++)
//		{
//			printf("%s\n",c[i]);
//		}
		col=0;
		for(int i=0;i<len;i++)
		{
			int flag=-1;
			int Max=0x3f3f3f3f;
			for(int j=0;j<len;j++)
			{
				if(vis[j]) continue;
				if(str[j]-'A'<Max)
				{
					Max=str[j]-'A';
					flag=j;
				}
			}
//			cout << flag<<endl;
			for(int k=0;k<Maxrow;k++)
			{
				ans[k][flag]=c[k][i];
//				cout << ans[k][flag];
			}
//			cout << endl;
			col++;
			vis[flag]=1;
		}
		for(int i=0;i<Maxrow;i++)
		{
			printf("%s",ans[i]);
		}
		cout <<endl;

	}
	
}
