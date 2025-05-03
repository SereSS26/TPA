#include <stdio.h>
#include <stdlib.h>

long long rezolvare(long long x,long long y,long long mo)
{
    long long nr=1;
    while(y!=0)
    {
        if(y%2==1)
        {
            nr=(nr*x)%mo;
        }
        x=(x*x)%mo;
        y=y/2;
    }
    return nr;
}
int main(void)
{
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Devu_vs_Police.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    gis=fopen("Devu_vs_Police.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    int T=0;
    long long x1=0,y1=0,x2=0,y2=0,mo=0;
    fscanf(fis,"%d",&T);
    while(T!=0)
    {   
        fscanf(fis,"%lld",&x1);
        fscanf(fis,"%lld",&y1);
        fscanf(fis,"%lld",&x2);
        fscanf(fis,"%lld",&y2);
        fscanf(fis,"%lld",&mo);
        fprintf(gis,"%lld\n",rezolvare(rezolvare(x1,y1,mo),rezolvare(x2,y2,mo),mo));
        T--;
    }
    fclose(fis);
    fclose(gis);
    
    return 0;
}