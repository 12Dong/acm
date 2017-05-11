#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
#define N 35
int n,m;
struct Matrix
{
	ll num[N][N];
};
Matrix multi(Matrix A,Matrix B)
{
	Matrix ans;
	memset(ans.num,0,sizeof(ans.num));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=0;k<n;k++)
			{
				ans.num[i][j]+=A.num[i][k]*B.num[k][j];
				ans.num[i][j]%=m;
			}
		}
	}
	return ans;
}
Matrix Matrix_plus(Matrix A,Matrix B)
{
	Matrix ans;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans.num[i][j]=A.num[i][j]+B.num[i][j];
			ans.num[i][j]=ans.num[i][j]%m;
		}
	 } 
	 return ans;
}

Matrix mat_quick_multi(Matrix a,int k)
{
	Matrix E;
	memset(E.num, 0, sizeof(E.num));
	for(int i=0;i<n;i++)
	{
		E.num[i][i]=1;
	}
	while(k>0)
	{
		if(k&1)
		{
			E=multi(E,a);
		}
		k>>=1;
		a=multi(a,a);
	}
	return E;
}

Matrix solve(Matrix a,int k)
{
	if(k==1) return a;
	Matrix ans;
	memset(ans.num,0,sizeof(ans.num));
	for(int i=0;i<n;i++)
	{
		ans.num[i][i]=1;
	}
	ans=Matrix_plus(ans,mat_quick_multi(a,k/2));
	ans=multi(ans,solve(a,k/2));
	if(k%2==1)
	{
		ans=Matrix_plus(ans,mat_quick_multi(a,k));
	}
	return ans;
}

void Display(Matrix A)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout << A.num[i][j]<<" ";
		}
		cout << endl;
	}
}
int main()
{
	int k;
	while(cin >> n>> k >> m)
	{
		Matrix A;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin >> A.num[i][j];
			}
		}
		
		Matrix ans;
		ans=solve(A,k);
		Display(ans);
		cout <<endl;

	}
}
