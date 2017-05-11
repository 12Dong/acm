#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 0x3f3f3f3f
typedef long long ll;
#define MAX 100010
using namespace std;
typedef pair <ll,int> p;
ll num[MAX],t,ans,tmp,sum;
int n,k,l,r,el,er;
p node[MAX];
ll myabs(ll n)
{
	if(n >=0) return n;
	else return -n;
}
int main()
{
	while(cin >> n >> k && n+k)
	{
		node[0]=p(0,0);
		for(int i=1;i<=n;i++)
		{
			cin >> num[i];
			node[i]=p(node[i-1].first+num[i],i);
		}
		sort(node,node+1+n);
		while(k--)
		{
			cin >> t;
			tmp=INF;
			l=0; r=1; //////
			while(r<=n)
			{
				sum=node[r].first-node[l].first;
				if(myabs(sum-t)<tmp)
				{
					tmp=myabs(sum-t);
					ans = sum;
					el= node[l].second;
					er= node[r].second;
				}
				if(sum>t) l++;
				else if(sum < t) r++;
				else break;
				if(l==r) r++;
			}
/*
			if(r<l)
			{
				swap(r,l);
			}
*/
//            cout <<el <<"   "<<er<<endl;
			if(er<el)
			{
				swap(er,el);
			}
			printf("%I64d %d %d\n", ans, el+1, er);
//			cout << ans << " "<< el+1 <<" "<< er <<endl;
			
		}
	}
}


/*
#include <cstdio>
#include <algorithm>
#include <cstring>
#define INF 0x3f3f3f3f
#define LL long long
#define MAX 100010
using namespace std;

typedef pair<LL, int> p;
LL a[MAX], t, ans, tmp, b;
int n, k, l, u, st, en;
p sum[MAX];

LL myabs(LL x)
{
    return x>=0? x:-x;
}

int main()
{
    while (scanf("%d %d", &n, &k), n+k){
        sum[0] = p(0, 0);
        for (int i = 1; i <= n; i++){
            scanf("%I64d", a+i);
            sum[i] = p(sum[i-1].first+a[i], i);
        }
        sort(sum, sum+1+n);
        while (k--){
            scanf("%I64d", &t);
            tmp = INF; st = 0, en = 1;
            while(en <= n){
                b = sum[en].first-sum[st].first;
                if(myabs(t-b) < tmp){
                    tmp = myabs(t-b);
                    ans = b;
                    l = sum[st].second; u = sum[en].second;
                }
                if(b > t) st++;
                else if(b < t) en++;
                else break;
                if(st == en) en++;
            }
            if (u < l) swap(u, l);
            printf("%I64d %d %d\n", ans, l+1, u);
        }
    }
    return 0;
}
*/
