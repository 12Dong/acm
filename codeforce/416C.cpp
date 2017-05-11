#include<iostream>
#include<cstring>
#include<algorithm>
//yr
using namespace std;
struct Group
{
	int mon;
	int people;
	int num;
 } group[1005];
 struct Vol
 {
 	int num;
 	int vol;
 }v[1005];
 bool cmp(Group a,Group b)
 {
 	return a.mon>b.mon;
 }
 bool cmp2(Vol a,Vol b)
 {
 	return a.vol<b.vol;
 }
 bool vis[1005];
 int ans[1005][2];
 int main()
 
 {
 	int n;
 	while(cin >> n)
 	{
 		memset(group,0,sizeof(group));
 		memset(vis,0,sizeof(vis));
 		memset(v,0,sizeof(v));
 		for(int i=0;i<n;i++)
 		{
 			cin >> group[i].people >> group[i].mon ; 
 			group[i].num=i+1;
		 }
		sort(group,group+n,cmp);
		int vol;
		cin >> vol;
		for(int i=0;i<vol;i++)
		{
			cin >> v[i].vol;
			v[i].num=i+1;
		}
		sort(v,v+vol,cmp2);
		int intAnscnt=0;
		int intAnssum=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<vol;j++)
			{
				if(vis[j]) continue;
				if(group[i].people<=v[j].vol)
				{
					vis[j]=1;
					ans[intAnscnt][0]=group[i].num;
					ans[intAnscnt][1]=v[j].num;
					intAnscnt++;
					intAnssum+=group[i].mon;
					
					break;
				}
			}
		}
		cout << intAnscnt << " "<< intAnssum<<endl;
		for(int i=0;i<intAnscnt;i++)
		{
			cout << ans[i][0]<< " "<<ans[i][1] << endl;
		}
	 }
 }
