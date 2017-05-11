#include<iostream>
using namespace std;
#define MOD 10000
typedef long long ll;
struct Matrix
{
	ll num[2][2];
};

Matrix multi(Matrix A,Matrix B)
{
	Matrix ans={0,0,0,0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				ans.num[i][j]+=A.num[i][k]*B.num[k][j];
				ans.num[i][j]%=MOD;
			}
		}
	}
	return ans;
}
void Display(Matrix A)
{
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			cout << A.num[i][j]<<"  ";
		 } 
		 cout << endl;
	}
}
Matrix mat_quick_multi(Matrix a,int n)
{
	Matrix E;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			E.num[i][j]=(i==j);
		}
	}
	while(n>0)
	{
		if(n&1)
		{
			E=multi(E,a);
		}
		n>>=1;
		a=multi(a,a);
	}
	return E;
}
int main()
{
	Matrix A=
	{
		1,1,1,0
	};
	int n;
	while(cin >> n)
	{
		if(n==-1) break;
		if(n==0) 
		{
			cout << 0 <<endl;
			continue; 
		} 
		Matrix E=mat_quick_multi(A,n-1);
		cout << E.num[0][0]<<endl;
	}
}
