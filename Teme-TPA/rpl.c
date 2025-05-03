#include <stdio.h>
#include <stdlib.h>
#define m 1999999973

void rpl(FILE *fis,FILE *gis)
{   
    long long int n=0,p=0,sol=1;
    fscanf(fis,"%lld",&n);
    fscanf(fis,"%lld",&p);
    n=n%m;
    while(p!=0)
    {
        if(p%2==1)
        {
            sol=(sol*n)%m;
        }
        n=(n*n)%m;
        p=p/2;
    }
    fprintf(gis,"%lld\n",sol);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("lgput.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier intrare\n");
        exit(-1);
    }
    gis=fopen("lgput.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier iesire\n");
        exit(-1);
    }
    rpl(fis,gis);
    fclose(fis);
    fclose(gis);

    return 0;
}