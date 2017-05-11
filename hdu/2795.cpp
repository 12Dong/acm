#include<iostream>
using namespace std;
int space[5*200000+5];
int curspace;
void pushup(int step)
{
	space[step]=max(space[step*2],space[step*2+1]);
}
void build(int l,int r,int step)
{
	if(l==r)
	{
		space[step]=curspace;
		return ;
	}
	int m=(l+r)/2;
	build(l,m,step*2);
	build(m+1,r,step*2+1);
	pushup(step);
}
void  update(int l,int r,int s,int step)
{
	if(space[step]<s) 
	{
		cout << -1 <<endl;
		return ;
	}
	else
	{
		if(l==r)
		{
			space[step]-=s;
			cout << l <<endl;
			return ;
		}
		int m=(l+r)/2;
		if(space[step*2]>=s)
		{
			update(l,m,s,step*2);
		}
		else
		{
			update(m+1,r,s,step*2+1);
		}
		pushup(step);
	}
}
int main()
{
	int h,n;
	while(cin >> h >> curspace >> n)
	{
		if(h>n) h=n;
		build(1,h,1);
		
		for(int i=0;i<n;i++)
		{
			int x;
			scanf("%d",&x);
			update(1,h,x,1);
		}

/*		for(int i=0;i<=10;i++)
		{
			cout << space[i]<<"  ";
		}
*/	
	}
	return 0;
}
