#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

const int M = 1e9+7;

struct Matrix {
	long long a[2][2];
	Matrix() {
		memset(a, 0, sizeof(a));
	}
	Matrix operator * (const Matrix y) {
		Matrix ans;
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= 1; j++)	
				for(int k = 0; k <= 1; k++)	
					ans.a[i][j] += a[i][k]*y.a[k][j];
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= 1; j++)
				ans.a[i][j] %= M;
		return ans;
	}
	void operator = (const Matrix b) {
		for(int i = 0; i <= 1; i++)
			for(int j = 0; j <= 1; j++)
				a[i][j] = b.a[i][j];
	}
};

void solve(long long x) {
	Matrix ans, trs;
	ans.a[0][0] = ans.a[1][1] = 1;
	trs.a[0][0] = trs.a[1][0] = trs.a[0][1] = 1;
	while(x) {
		if(x&1) 
			ans = ans*trs;
		trs = trs*trs;
		x >>= 1;
	}
	for(int i=0;i<=1;i++)
	{
			for(int j=0;j<=1;j++)
          	cout << ans.a[i][j]<<"   ";
          	cout << endl;
	}
}

int main() {
	int n;
	
	while(scanf("%d", &n)==1)
	solve(n-1);
	return 0;
}
