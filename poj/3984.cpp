#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
using namespace std;
int map[5][5];
int vis[5][5];
int step[5][5];
struct node
{
	int x;
	int y;
};
int dir[4][2]={1,0,-1,0,0,1,0,-1};
int main()
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=5;i++)
	for(int j=1;j<=5;j++)
	cin >> map[i][j];
	queue <node> q;
	node n;
	n.x=1;
	n.y=1;
	q.push(n);
	int flag=0;
	while(!q.empty())
	{
		
		node m=q.front();
		q.pop();
//		cout << m.x <<  "     "<< m.y << endl;
		if(m.x<1 || m.x>5)
		{
			cout << 1 << endl;
			continue;
		}
		if(m.y<1 || m.y>5)
		{
			cout << 2 << endl;
			continue;
		}		
		if(step[m.x][m.y]) 
		{
			continue;
		}
		if(m.x==5 && m.y==5) 
		{
			break;
		}
		step[m.x][m.y]=1;
		node New=m;
		for(int i=0;i<4;i++)
		{
			New.x+=dir[i][0];
			New.y+=dir[i][1];
			vis[New.x][New.y]=m.x*10+m.y;
			q.push(New);
		}
	}
	stack <node> s;
	node m;
	m.x=5;
	m.y=5;
	s.push(m);
	cout << 1 <<endl;
	for(int i=1;i<=5;i++)
	{
			for(int j=1;j<=5;j++)
	{
		cout << vis[i][j]<<"   "; 
	}
	cout <<endl;
	}
	/*
	while(vis[m.x][m.y]!=0)
	{
		node tmp;
		
		tmp.x=vis[m.x][m.y]/10;
		tmp.y=vis[m.x][m.y]%10;
		cout <<  tmp.x << "   "<<tmp.y<<endl;
		m.x=tmp.x;
		m.y=tmp.y;
	}
	*/
	cout << 2 << endl;
/*	while(!s.empty())
	{
		node a =s.top();
		s.pop();
		cout <<"("<<a.x <<","<<a.y<<")"<<endl;
	}
*/	
	return 0;
}

