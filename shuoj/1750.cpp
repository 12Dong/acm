#include<iostream>
using namespace std;
struct Node
{
	Node * next;
	Node *pri;
	int id;
	Node(){	}
	Node(int data=0,Node*p=NULL,Node*n=NULL)
	{
		id=data;
		pri=p;
		next=n;
	}
	
};

int main()
{
	int n,m,k;
	while(cin >> n >> m >> k)
	{
		int cnt=1;
		Node *s=new Node(1,s,s);
		Node *t=s;
		while(cnt<n)
		{
			Node *p=new Node(++cnt,t);
			t->next=p;
			t=t->next; 
		}
		t->next=s;
		s->pri=t;
		Node *p=s;
		while(p->id!=k)
		{
			p=p->next; 
		}
		cnt=1;
		while(p->next!=p)
		{
//			cout << cnt <<"    "<<p->id<<endl;
			if(cnt!=m)
			{
				cnt++;
				p=p->next;
			}
			else 
			{
				cnt=1;
//				cout << p->id<<endl;
				p->next->pri=p->pri;
				p->pri->next=p->next;
				p=p->next;
			}
		}
		cout << p->id<<endl;
	}
}
