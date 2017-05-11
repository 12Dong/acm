#include<iostream>
using namespace std;
int main()
{
	int ex,nb;
	cin >> ex >> nb;
	int ans=(ex+nb)/3;
	int ansEX=ex;
	int ansNB=nb;
	int Ans=min(ans,ansEX);
	Ans=min(Ans,ansNB);
	cout <<Ans <<endl;
}
