#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define MAX 1007

using namespace std;
char s[MAX];
int maxPrime[MAX];
int mark[MAX];
int num[30];

void init ()
{
    memset ( maxPrime , -1 , sizeof ( maxPrime ) );
    for ( int i = 2 ; i < MAX ; i++ )
    {
        if (~maxPrime[i]) continue;
        for ( int j = i*2 ; j < MAX ; j += i )
            maxPrime[j] = i;
    }
}

int main ( )
{
    init ();
    while (~scanf ( "%s" , s ) )
    {
        int n = strlen ( s );
        memset ( mark , 0 , sizeof ( mark ) );
        if ( n < 4 )
        {
            puts ( "YES" );
            puts ( s );
            continue;
        }
        int cnt = 2;
        for ( int i = n ; i >= 2; i-- )
        {
            if ( mark[i] && maxPrime[i] == -1 ) continue;
            if ( ~maxPrime[i] )
            {
                mark[i] = true;
                for ( int j = 2 ; j*j <= i ; j++ )
                {
                    if ( i%j ) continue;
                    mark[j] = mark[i/j] = true;
                }
            }
            else cnt++;
        }
        memset ( num , 0 , sizeof ( num ));
        for ( int i = 0 ; i < n ; i++ )
            num[s[i]-97]++;
        int id = -1;
        for ( int i = 0 ; i < 26 ; i++ )
            if ( n-cnt+1 <= num[i] )
            {
                id = i;
                num[i] -= (n-cnt+1);
                break;
            }
        if ( id == -1 )
        {
            puts ( "NO" );
            continue;
        }
        for ( int i = 0 ; i < n ; i++ )
        {
            if ( mark[i+1] ) s[i] =(char)(id+97);
            else
            for ( int j = 0 ; j < 26 ; j++ )
                if ( num[j] )
                {
                    num[j]--;
                    s[i] = (char)(j+97);
                    break;
                }
        }
        puts ( "YES");
        puts ( s );
    }
}
