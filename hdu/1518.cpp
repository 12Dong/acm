#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int l[25];
int s1,s2,s3,s4;
int sum;
int vis[25];
int suma;
bool ans;
int num;
void  dfs(int n)
{
	if(ans) return ;
	if(n>num) return;
	if(s1>sum/4 || s2>sum/4 || s3>sum/4 ||  s4>sum/4 ) return ;
	if(s1==sum/4 && s2==sum/4 && s3==sum/4 &&  s4==sum/4 ) 
	{
		ans=1;
		return ;
	}
	if(s1==sum/4) suma++;
	if(s2==sum/4) suma++;
	if(s3==sum/4) suma++;
	if(s4==sum/4) suma++;
	if(suma>=3) 
	{
		ans=1;
		return ;
	}
	if(vis[n-1]!=1) 
	{
		if(s1+l[n]<=sum/4)
		{
			s1+=l[n];
			vis[n]=1;
			dfs(n+1);
			s1-=l[n];
			vis[n]=0;		
		}
	}
	
	if(vis[n-1]!=2)
	{
		if(s2+l[n]<=sum/4)
		{
			s2+=l[n];
			vis[n]=2;
			dfs(n+1);
			s2-=l[n];
			vis[n]=0;		
		}
	} 
	
	if(vis[n-1]!=3) 
	{
		if(s3+l[n]<=sum/4)
		{
			s3+=l[n];
			vis[n]=3;
			dfs(n+1);
			s3-=l[n];
			vis[n]=0;		
		}	
	}
	
	if(vis[n-1]!=4)
	{
		if(s4+l[n]<=sum/4)
		{
			s4+=l[n];
			vis[n]=4;
			dfs(n+1);
			s4-=l[n];
			vis[n]=0;		
		}	
	}
	
	
	suma=0;
}
int main()
{
	int cases;
	scanf("%d",&cases);
	while(cases--)
	{
		suma=0;
		ans=0;
		s1=0,s2=0,s3=0,s4=0;
		sum=0;
		memset(l,0,sizeof(l));
		cin >> num;
		for(int i=0;i<num;i++)
		{
			scanf("%d",&l[i]);
			sum+=l[i];
		}
		sort(l,l+num);
		if(sum%4==0 && l[num-1]<=sum/4 && num>=4)
		dfs(0);
		if(ans) printf("yes\n");
		else printf("no\n");
	}
}
