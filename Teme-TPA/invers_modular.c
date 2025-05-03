#include <stdio.h>
#include <stdlib.h>

void inversmodular(FILE *fis,FILE *gis)
{
    long long int a=0,n=0,y=0,y0=0,y1=1,aux=0,r=0,c=0;
    fscanf(fis,"%lld",&a);//citim datele din fisiere
    fscanf(fis,"%lld",&n);
    aux=n;//stocam intr-o variabila auxiliara valoarea initiala a lui n
    while(a!=0)//aplicam algorimtul lui euclid extins iterativ din curs cu complexitate O(log(min(a,n))),adica O(log(a)) aici
    {
        r=n%a;
        c=n/a;//la fiecare pas calulcam restul si catul impartirii lui n la a(n mai mare ca a aici)
        n=a;//se actulaizeaza n si a cu noile valori
        a=r;
        y=y0-c*y1;
        y0=y1;
        y1=y;
    }
    while(y0<0)
    {
        y0=aux+y0;
    }
    fprintf(gis,"%lld\n",y0);//scriem solutia in fisier
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("inversmodular.in","r");//deschidem fisierele
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier de intrare\n");
        exit(-1);
    }
    gis=fopen("inversmodular.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier de iesire\n");
        exit(-1);
    }
    inversmodular(fis,gis);//rezolvare
    fclose(fis);//inchidem fisierele
    fclose(gis);

    return 0;
}