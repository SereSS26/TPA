#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
}Punct;
double rezolvare(Punct origine,Punct directie,Punct colt_stanga_jos,Punct colt_dreapta_sus)
{
    double aux=0,x_mini=0,x_maxi=0,y_mini=0,y_maxi=0;
    x_mini=(colt_stanga_jos.x-origine.x)/directie.x;
    x_maxi=(colt_dreapta_sus.x-origine.x)/directie.x;
    if(x_mini>x_maxi)
    {
        aux=x_mini;
        x_mini=x_maxi;
        x_maxi=aux;
    }
    y_mini=(colt_stanga_jos.y-origine.y)/directie.y;
    y_maxi=(colt_dreapta_sus.y-origine.y)/directie.y;
    if(y_mini>y_maxi)
    {
        aux=y_mini;
        y_mini=y_maxi;
        y_maxi=aux;
    }
    if((x_mini>y_maxi)||(y_mini>x_maxi))
    {
        return -1.0;
    }
    if(y_mini>x_mini) 
    {
        x_mini=y_mini;
    }
    if(y_maxi<x_maxi) 
    {
        x_maxi=y_maxi;
    }
    return sqrt(x_mini*x_mini+y_mini*y_mini);
}
void citire(FILE *fis,FILE *gis)
{
    Punct origine;
    Punct directie;
    Punct colt_stanga_jos;
    Punct colt_dreapta_sus;
    double distanta=0;
    fscanf(fis,"%lf",&origine.x);
    fscanf(fis,"%lf",&origine.y);
    fscanf(fis,"%lf",&directie.x);
    fscanf(fis,"%lf",&directie.y);
    fscanf(fis,"%lf",&colt_stanga_jos.x);
    fscanf(fis,"%lf",&colt_stanga_jos.y);
    fscanf(fis,"%lf",&colt_dreapta_sus.x);
    fscanf(fis,"%lf",&colt_dreapta_sus.y);
    distanta=rezolvare(origine,directie,colt_stanga_jos,colt_dreapta_sus);
    if(distanta>=0)
    {
        fprintf(gis,"DA %lf\n",distanta);
    }
    else
    {
        fprintf(gis,"NU\n");
    }
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Problema10.in","r");
    if(fis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    gis=fopen("Problema10.out","w");
    if(gis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    citire(fis,gis);
    fclose(fis);
    fclose(gis);

    return 0;
}