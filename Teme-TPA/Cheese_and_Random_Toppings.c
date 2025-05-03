#include <stdio.h>
#include <stdlib.h>

long long rezolvare(long long r,long long n,long long m)
{
    
}
int main(void)
{   
    int T=0;
    long long r=0,n=0,m=0;
    long long rez=0;
    scanf("%d",&T);
    while(T!=0)
    {
        scanf("%lld",&r);
        scanf("%lld",&n);
        scanf("%lld",&m);
        rez=rezolvare(r,n,m);
        printf("%lld\n",rez);
        T--;
    }

    return 0;
}