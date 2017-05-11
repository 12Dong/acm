#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	int sum=0;
	for(int i=0;i<num;i++)
	{
		int tmp;
		cin >> tmp;
		sum+=tmp;	
	}
	for(int i=0;i<2;i++)
	{
		num--;
		int sumres=0;
		for(int j=0;j<num;j++)
		{
			int tmp;
			cin >> tmp;
			sumres+=tmp;
		}
		cout << sum-sumres<<endl;
		sum=sumres; 
	}
}
