#include <stdio.h>
#include <stdlib.h>
int num[10000];
int used[10001];
int m, n;
int t;
 
void output(void)
{
    int i;
    for(i = 0; i < n; i++){
        if(i != 0){
            printf(" ");
        }
        printf("%d", num[i]);
    }
    printf("\n");
    exit(0);
}
 
void srch(int now, int start)
{
    int i;
    if(now == n){
        if(t == m){
            output();
        }
        t++;
        return;
    }
    for(i = start; i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            num[now] = i;
            srch(now + 1, num[now + 1]);
            used[i] = 0;
        }
    }
    if(now != 0){
        num[now] = num[now - 1] + 1;
    }
    num[now] = 1;
}
 
int main(int argc, char **argv)
{
    int i;
    scanf("%d%d", &n, &m);
    for(i = 0; i < n; i++){
        scanf("%d", &num[i]);
    }
    srch(0, num[0]);
    return 0;
}
