#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f2(double x,double *an,double precizie)//functia are trei parametrii:x->numarul al carui radical dorim sa-l calculam,an->valoarea radicalului la un moment dat,precizie->precizia
{
    double urm=0;
    urm=0.5*((*an)+x/(*an));//elementul urmator din sirul babilonian calculat dupa formula din enunt
    if(fabs(urm-(*an))<=precizie)//daca se respecta precizia am ajuns la un rezultat satisfacator
        return urm;
    else
        return f2(x,&urm,precizie);//altfel apelam recursiv functia cu noua valoare din sirul babilonian(urm=an+1)
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    double x=0,a0=1.0,an=0,precizie=0;
    fis=fopen("2.in","r");
    if(fis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    gis=fopen("2.out","w");
    if(gis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    fscanf(fis,"%lf",&x);//citim din fiser numarul al carui radical dorim sa-l gasim
    an=a0;//la inceput an este egal cu 1,adica cu a0
    fscanf(fis,"%lf",&precizie);//citim din fiser precizia cu care dorim sa calculam radicalul
    fprintf(gis,"%lf\n",f2(x,&an,precizie));//f2->functia de gasire a valorii radicalului cu metoda babiloniana recursiva
    fclose(fis);//inchidere fisiere
    fclose(gis);

    return 0;
}