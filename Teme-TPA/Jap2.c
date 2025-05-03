#include <stdio.h>
#include <stdlib.h>

void euclid_extins(long long int a, long long int b, long long int *x, long long int *y)
{
    if(b==0)
    {
        *x=1;
        *y=1;
    }
    else
    {
        long long int x1, y1;
        euclid_extins(b,a%b,&x1,&y1);
        *x=y1;
        *y=x1-a/b*y1;
    }
}
long long int inversModular(long long int a, long long int b)
{
    long long int x, y;
    euclid_extins(a,b,&x,&y);
    if(x<=0)
    {
        x=b+x%b;
    }
    return x;
}
long long int combinari(long long int n,long long int k,long long int p,long long int *factorial)
{
    if(n<k)
        return 0;
    else
        return factorial[n]*inversModular(factorial[k],p)%p*inversModular(factorial[n-k],p)%p;
}
void jap2(FILE *fis,FILE *gis)
{
    long long int p=0,q=0,a=0,b=0,i=0,r=0,factorial[100008];
    fscanf(fis,"%lld",&p);
    fscanf(fis,"%lld",&q);
    factorial[0]=1;
    for(i=1;i<=100008;i++)
    {
        factorial[i]=(factorial[i-1]*i)%p;
    }
    for(i=0;i<q;i++)
    {
        fscanf(fis,"%lld",&a);
        fscanf(fis,"%lld",&b);
        r=1;
        while(a>0&&b>0)
        {
            r=(r*combinari(a%p,b%p,p,factorial))%p;
            a=a/p;
            b=b/p;
        }
        fprintf(gis,"%lld\n",r);
    }
}
int main(void)
{
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("jap2.in","r");//deschidem fisiere
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    gis=fopen("jap2.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisier\n");
        exit(-1);
    }
    jap2(fis,gis);//rezolvare
    fclose(fis);//inchidem fisiere
    fclose(gis);

    return 0;
}