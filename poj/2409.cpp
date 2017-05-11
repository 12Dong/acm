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
//��ת�ͷ�ת����Ϊ��ͬ
	long long sum=0;//cΪ��ɫ��
	for (int i=0;i<n;i++){	//�����i����ת��0->i
		for (int j=0;j<n;j++)
			perm[j]=(i+j)%n;
		
		sum=sum+power(color,cycle());
	}
	if(n%2==1)    		//�����i����ת
		for (int i=0;i<n;i++){	//i���ֲ���
			for (int j=0;j<n;j++)
				perm[(i+j)%n]=(i-j+n)%n;
			sum=sum+power(color,cycle());
		}
	else if(n%2==0)
		for (int i=0;i<(n/2);i++){		//�����i����ת
			for (int j=0;j<n;j++)	//i���ֲ�������n/2��
				perm[(i+j)%n]=(i-j+n)%n;
			sum=sum+power(color,cycle());
			for (int j=0;j<n;j++) 
					//i?i+1��i-1?i+2��������n/2��
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
 		cout <<"��������ɫ�����Բ���Ľڵ���"<<endl;
		cin >> color >> n; 
 		if(color==0 && n==0) break;
 		cout <<"��ͬ���Ϊ  " <<polya(color,n)<<endl;
	 }
 }
