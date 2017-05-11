#include<iostream>
using namespace std;
typedef long long ll;
#define Mod 10007
struct Matrix
{
	ll num[2][2];
};
Matrix multi(Matrix a,Matrix b)
{
	Matrix ans={0,0,0,0};
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				ans.num[i][j]=(ans.num[i][j]+(a.num[i][k]*b.num[k][j])%Mod)%Mod;
			}
		}
	}
	return ans;
}
Matrix Matrix_quick_mat(Matrix x,int k)
{
	Matrix E={1,0,0,1};
	while(k>0)
	{
		if(k&1)
		{
			E=multi(E,x);
		}
		k>>=1;
		x=multi(x,x);
	}
	return E;
}
int main()
{
	int n;
	Matrix matrix={1,1,1,0};
	while(cin >> n)
	{
		cout << Matrix_quick_mat(matrix,n-1).num[0][0]<<endl;
	}
}
