#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int map[26][26];
int vis[26];
int flag;
void dfs(int x,int y)
{
	if(vis[x]) return ;
	vis[x]=1;
	if(x==y) 
	{
		flag=1;
		return ;
	}
	for(int i=0;i<26;i++)
	{
		if(map[x][i]==1)
		{
			dfs(i,y);
			
		}
	}
}
int main()
{
	string str;
	flag=0;
	memset(vis,0,sizeof(vis));
	memset(map,0,sizeof(map));
	while(cin >>str)
	{
		flag=0;
		map[str[0]-'a'][str[str.size()-1]-'a']=1;
		while(cin >> str && str[0]!='0')
		{
			map[str[0]-'a'][str[str.size()-1]-'a']=1;
		}		
	    dfs('b'-'a','m'-'a');
	    if(flag==1) cout <<"Yes."<<endl;
	    else cout <<"No."<<endl;
	    memset(vis,0,sizeof(vis));
	    memset(map,0,sizeof(map));
}
}
