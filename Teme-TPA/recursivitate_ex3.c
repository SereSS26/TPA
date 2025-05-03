#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x) 
{
    return pow(x,5)+x-1;//exemplu de funcție
}
double f3(double (*f)(double),double a,double b,double tol)//metoda bisectiei recursiva
{   
    double c=0;
    c=(a+b)/2;
    if(b-a<=tol)//daca am ajuns la o solutie care e potrivita e ok
        return (b+a)/2;
    else
    {   
        if(f(a)*f(c)<0)//folosim algoritmul de la metoda bisectiei
            return f3(f,a,c,tol);
        if(f(b)*f(c)<0)
            return f3(f,c,b,tol);
    }
    return c;//daca f(c)==0, atunci c este radacina
}
int main(void)
{
    FILE *fis=NULL,*gis=NULL;//fisiere
    double a=0,b=0,tol=0;//a si b reprezinta capetele intervalului si tol toleranta
    fis=fopen("3.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier intrare\n");
        exit(-1);
    }
    gis=fopen("3.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier iesire\n");
        exit(-1);
    }
    fscanf(fis,"%lf",&a);
    fscanf(fis,"%lf",&b);
    fscanf(fis,"%lf",&tol);
    fprintf(gis,"%lf",f3(f,a,b,tol));//folosim metoda bisectiei pe care o stim de la MAC
    fclose(fis);//inchidem fisiere
    fclose(gis);

    return 0;
}