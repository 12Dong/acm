#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
int n,m;
int ans;
bool vis[30000];
const int MAX=25000;
struct Node
{
	int num;
	int times;
};
void bfs(int n,int m)
{
	queue<Node> q;
	Node start;
	start.num=n;
	start.times=0; 
	q.push(start);
	while(!q.empty())
	{	
		Node tmp=q.front();
		q.pop();
		Node cur1,cur2;
		cur1=cur2=tmp;
		cur1.num--;
		cur1.times++;
		cur2.num*=2;
		cur2.times++;
		if(cur1.num==m)
		{
			cout << cur1.times << endl;
			break;
		}
		if(cur2.num==m)
		{
			cout << cur2.times << endl;
			break;
		}
		if(cur1.num>0 && cur1.num<=MAX && vis[cur1.num]==0)
		{
			q.push(cur1);
			vis[cur1.num]=1;
		}
		if(cur2.num>0 && cur2.num<=MAX && vis[cur2.num]==0)
		{
			q.push(cur2);
			vis[cur2.num]=1;
		}
	}	
}
int main()
{
	while(cin >> n >> m)
	{
		memset(vis,0,sizeof(vis));
		bfs(n,m);
	}
}
