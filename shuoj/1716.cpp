#include<iostream>
#include<queue>
using namespace std;
int main()
{
	priority_queue<int,vector<int>,greater<int> > q;
	int n;
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		{
			int a;
			cin >> a;
			q.push(a);
		}
		int ans=0;
		while(!q.empty())
		{
			int a=q.top(); 
			q.pop();
			if(q.empty())
			{
				break;
			}
			int b=q.top();
			q.pop();
			ans+=a+b;
			q.push(a+b);
		}
		cout << ans <<endl;
	}
	
}
