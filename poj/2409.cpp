//poj2409
#include<iostream>
#include<cstring>
#include<cmath>
int vis[100];
int perm[100];
int n;
long long power(int n,int x)
{
	long long ans=1;
	for(int i=1;i<=x;i++)
	{
		ans=ans*n;
	}
	return ans;
}
using namespace std;
int cycle(){
	int pos,sum=0;
    memset(vis,0,sizeof(vis));
	for (int i=0;i<n;i++)
		if (!vis[i]){
			sum++;
                        pos=i;
			for (int j=0;!vis[perm[pos]];j++){
				pos=perm[pos];
				vis[pos]=1;
			}
		}
	return sum;
} 
long long polya(int color,int n){	
//旋转和翻转下视为相同
	long long sum=0;//c为颜色数
	for (int i=0;i<n;i++){	//构造第i个旋转，0->i
		for (int j=0;j<n;j++)
			perm[j]=(i+j)%n;
		
		sum=sum+power(color,cycle());
	}
	if(n%2==1)    		//构造第i个翻转
		for (int i=0;i<n;i++){	//i保持不动
			for (int j=0;j<n;j++)
				perm[(i+j)%n]=(i-j+n)%n;
			sum=sum+power(color,cycle());
		}
	else if(n%2==0)
		for (int i=0;i<(n/2);i++){		//构造第i个翻转
			for (int j=0;j<n;j++)	//i保持不动，共n/2个
				perm[(i+j)%n]=(i-j+n)%n;
			sum=sum+power(color,cycle());
			for (int j=0;j<n;j++) 
					//i?i+1，i-1?i+2，…，共n/2个
				perm[(i-j+n)%n]=(i+j+1)%n; 
			sum=sum+power(color,cycle());
		}
	return sum/(2*n);
}
 int main()
 {
 	int color;
 	while(true)
 	{
 		cout <<"请输入颜色和组成圆环的节点数"<<endl;
		cin >> color >> n; 
 		if(color==0 && n==0) break;
 		cout <<"不同组合为  " <<polya(color,n)<<endl;
	 }
 }
