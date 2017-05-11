#include<iostream>
#include<algorithm>
using namespace std;
struct Node
{
	int book;
	double cost;
}node[3];
bool cmp(Node a, Node b)
{
	return a.cost < b.cost;
}
int main()
{
	int cases;
	cin >> cases;
	while(cases--)
	{
		int n;
		double a,b,c;
		cin >> n >> a >> b >> c;
		if(n%4==0)
		{
			cout << 0 << endl;
			continue;
		}
		node[0].book=1;
		node[0].cost=a;
//		cout << node[0].cost<<endl;
		node[1].book=2;
		node[1].cost=b/2;
//		cout << node[1].cost<<endl;
		node[2].book=3;
		node[2].cost=c/3;
//		cout << node[2].cost<<endl;
		sort(node,node+3,cmp);
		int need=((n/4+1)*4-n);
//		cout <<"!!"<<node[0].book<<"  "<<node[1].book<<"  "<<node[2].book<<"  "<<endl;
//		cout <<"**"<<need << endl;
		int C=0;
		for(int i=0;i<=2;i++)
		{
			if(need==0) break;
			C=(need/node[i].book)*(node[i].book*node[i].cost);
			need=need-need/node[i].book*node[i].book;
			
		}
		cout << C << endl;
	}
}
