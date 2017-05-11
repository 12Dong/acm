#include<cstdio>
#include<iostream>
#include<map>
#include<set>
using namespace std;
#define INF 0x3f3f3f3f
int num[1000005];
map <int,int> cnt;
set <int>t;
int main()
{
	int n;
	while(scanf("%d",&n)==1 )
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&num[i]);
			t.insert(num[i]);
		}
		int l=0,r=0;
		int ans=INF;
		int sum=0;
		int Num=t.size();
		while(1)
		{
			while(r<n && sum<Num)
        	if (cnt[num[r++]]++ == 0) sum++;  
//			if(cnt[num[r++]]++==0) sum++;
			if(sum <Num) break;
			ans=min(ans,r-l);
			
			if(--cnt[num[l++]]==0) sum--;
		}
		cout << ans <<endl;
	}
}
/*

#include <cstdio>
#include <set>
#include <map>
#define MAX 1000010
#define INF 0x3f3f3f3f

using namespace std;
int a[MAX];
map <int, int> cnt;
set <int> t;
int p, ans = INF, st, en, sum;

int main()
{
    scanf("%d", &p);
    for (int i = 0; i < p; i++) scanf("%d", a+i), t.insert(a[i]);
    int num = t.size();
    while (1){
        while (en<p && sum<num)
            if (cnt[a[en++]]++ == 0) sum++;
        if (sum < num) break;
        ans = min(ans, en-st);
        if (--cnt[a[st++]] == 0) sum--;
    }
    printf("%d\n", ans);
    return 0;
}
*/
