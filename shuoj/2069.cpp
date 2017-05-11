#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct node
{
	int time;
	int num;
}times[200005];
int main()
{
	int n;
	int num[200005];
	while(cin >> n)
	{
		for(int i=0;i<n;i++)
		cin >> num[i];
		sort(num,num+n);
		int loc=0;
		int f=0;
		for(int i=0;i<n-1;i++)
		{
			if(num[i]!=num[i+1])
			{
				times[f].num=num[i];
				times[f++].time=i-loc+1;
				
				loc=i+1;
			}
		}
		if(num[n-1]==num[n-2]) 
		{
			times[f].time=n-loc;
			times[f].num=num[n-1];
		}
		else 
		{
			times[f].time=1;
			times[f].num=num[n-1];
		}
		for(int i=0;i<=f;i++)
		{
			cout << times[i].time <<"  "<<times[i].num<<endl;
		}
		cout << endl;

}}
