#include <stdio.h>
#include <stdlib.h>

long long superpower1(long long x,long long a,long long b)
{
    long long nr=1;
    while(a!=0)
    {
        if(a%2==1)
        {
            nr=(nr*x);
        }
        x=(x*x);
        a=a/2;
    }
    return nr;
}
long long superpower2(long long x,long long a,long long b)
{
    long long nr=1;
    while(a!=0)
    {
        if(a%2==1)
        {
            nr=(nr*x)%b;
        }
        x=(x*x)%b;
        a=a/2;
    }
    return nr;
}
int main(void)
{
    long long a=0,b=0,rez=0;
    scanf("%lld",&a);
    scanf("%lld",&b);
    rez=superpower2(2,superpower1(2,a,b),b);
    printf("%lld\n",rez);

    return 0;
}