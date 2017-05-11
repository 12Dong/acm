#include<iostream>
#include<cstring>
#define INF 0x3f3f3f3f
using namespace std;
long long n,m; //n���ĸ��� m����λ�� 
long long s;//����� 
long long b[110000][10];
long long tmp[10];//���˳�� 
long long flag[10];//��λ�Ƿ�ʹ�� 
long long ma,mi;
char a[10][10];
long long ans;

void dfs(int k) //��kλ 
{
	if(k>m)
	{
		for(int i=1;i<=m;i++)
		{
			b[s][i]=tmp[i];   //��s��ȫ���� 
		}
		s++;
		return ;
	}
	for(int i=1;i<=m;i++)
	{
		if(!flag[i])
		{
			tmp[k]=i;
			flag[i]=true;
			dfs(k+1);
			flag[i]=false;
		}
		
	}
}

int main()
{
	char num[100][10];
	
	while(cin >> n >> m)
	{
		for(int i=1;i<=n;i++)
		{
			cin >> num[i];
		}
		s=0;
		memset(flag,false,sizeof(flag));
		dfs(1);
		long long ans=INF;
		for(long long i=0;i<s;i++)
		{
			long long intcurMax=-1;
			long long intcurMin=INF;
			for(long long j=1;j<=n;j++)
			{
				long long intcurSvalue=0;
				for(long long k=0;k<m;k++)
				{
					intcurSvalue=intcurSvalue*10+(num[j][b[i][k+1]-1]-'0');
				}
				intcurMax=max(intcurMax,intcurSvalue);
				intcurMin=min(intcurMin,intcurSvalue);
			}
			ans=min(ans,intcurMax-intcurMin);
		}
		cout << ans <<endl;
	}
}

