#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    char nume[20];
    int nota;
}Student;
typedef struct
{
    char nume[20];
    unsigned int dimensiune:10;
    unsigned int tip1:2;
    unsigned int tip2:1;
}Fisier;
typedef struct
{
    unsigned int picioare:10;
    double greutate;
    unsigned int periculos:1;
    char abreviere[8];
    unsigned int varsta:11;
}Animal;
typedef struct
{
    unsigned int grad_periculozitate:2;
    unsigned int reteta:1;
    unsigned int varsta:5;
}Medicament;
typedef struct
{
    unsigned int valoare :10;
    unsigned int multiplicator:3;
    unsigned int unitate:3;
}Masuratoare;

void f4_0(FILE *fis,FILE *gis)
{
    Student S;
    fscanf(fis,"%20s",S.nume);
    fscanf(fis,"%d",&S.nota);
    fprintf(gis,"%s ",S.nume);
    fprintf(gis,"%d\n",S.nota);
}
void f4_1(FILE *fis,FILE *gis)
{   
    Fisier F;
    fscanf(fis,"%20s",F.nume);
    int aux=0;
    fscanf(fis,"%d",&aux);
    F.dimensiune=aux;
    fscanf(fis,"%d",&aux);
    F.tip1=aux;
    fscanf(fis,"%d",&aux);
    F.tip2=aux;
    fprintf(gis,"%s ",F.nume);
    fprintf(gis,"%u ",F.dimensiune);
    fprintf(gis,"%u ",F.tip1);
    fprintf(gis,"%u\n",F.tip2);
}
void f4_2(FILE *fis,FILE *gis)
{
    Fisier F[10];
    int i=0,aux=0,n=0;
    fscanf(fis,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%20s",F[i].nume);
        fscanf(fis,"%d",&aux);
        F[i].dimensiune=aux;
        fscanf(fis,"%d",&aux);
        F[i].tip1=aux;
        fscanf(fis,"%d",&aux);
        F[i].tip2=aux;
    }
    for(i=0;i<n;i++)
    {
        fprintf(gis,"%s ",F[i].nume);
        fprintf(gis,"%u ",F[i].dimensiune);
        fprintf(gis,"%u ",F[i].tip1);
        fprintf(gis,"%u ",F[i].tip2);
    }
}
void f4_3(FILE *fis,FILE *gis)
{
    Fisier *F=NULL;
    F=(Fisier*)malloc(10*sizeof(Fisier));
    if(F==NULL)
    {
        perror("eroare la alocarea dinamica a memroiei\n");
        exit(-1);
    }
    int i=0,aux=0,n=0;
    fscanf(fis,"%d",&n);
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%20s",F[i].nume);
        fscanf(fis,"%d",&aux);
        F[i].dimensiune=aux;
        fscanf(fis,"%d",&aux);
        F[i].tip1=aux;
        fscanf(fis,"%d",&aux);
        F[i].tip2=aux;
    }
    for(i=0;i<n;i++)
    {
        fprintf(gis,"%s ",F[i].nume);
        fprintf(gis,"%u ",F[i].dimensiune);
        fprintf(gis,"%u ",F[i].tip1);
        fprintf(gis,"%u\n",F[i].tip2);
    }
    free(F);
}
void f4_4(FILE *fis,FILE *gis)
{
    printf("%lu\n",sizeof(Animal));
    //citire animal daca e cazul
}
void f4_5(FILE *fis,FILE *gis)
{
    printf("%lu\n",sizeof(Medicament));
    //citire medicament daca e cazul
}
void f4_6(FILE *fis,FILE *gis)
{
    int valoare=0,unitate=0;
    fscanf(fis,"%d",&valoare);
    fscanf(fis,"%d",&unitate);
    int multiplicator=0,val=0;
    if(valoare<1000) 
    {
        val=valoare;
        multiplicator=0;
    }
    else if (valoare < 1000000) 
    {
        val=valoare/1000;
        multiplicator=2;
    }
    else if(valoare<1000000000) 
    {
        val=valoare/1000000;
        multiplicator=7;
    }
    else
    {   
        multiplicator=-1;
    }
    if(multiplicator==-1)
    {
        printf("Valoarea e prea mare\n");
    }
    Masuratoare M;
    M.valoare=val;
    M.multiplicator=multiplicator;
    M.unitate=unitate;
    printf("%d ",M.valoare);
    printf("%d ",M.multiplicator);
    printf("%d\n",M.unitate);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Lab4.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului de intrare\n");
        exit(-1);
    }
    gis=fopen("Lab4.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului de iesire\n");
        exit(-1);
    }
    ///PROBLEME USOARE
    f4_0(fis,gis);
    f4_1(fis,gis);
    f4_2(fis,gis);
    f4_3(fis,gis);
    ///PROBLEME MEDII
    f4_4(fis,gis);
    f4_5(fis,gis);
    f4_6(fis,gis);
    ///PROBLEME DATE LA EXAMEN
    ///...
    return 0;
}