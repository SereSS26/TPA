#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct
{   
    char nume[20];
    int x;
}Student;
int Compara_rezultat(const void *el1,const void *el2)
{
    const Student *rezultat1=(const Student *)el1;
    const Student *rezultat2=(const Student *)el2;
    if(rezultat1->x>rezultat2->x)
        return -1;
    else
    {
        if(rezultat1->x==rezultat2->x)
        {
            return strcmp(rezultat1->nume,rezultat2->nume);
        }
        else
            return 1;
    }
}
void f2_1(FILE *fis,FILE *gis)
{
    int n=0,i=0;
    Student *rezultat=NULL;
    fscanf(fis,"%d",&n);
    rezultat=(Student*)malloc(n*sizeof(Student));
    if(rezultat==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%20s",rezultat[i].nume);
        fscanf(fis,"%d",&rezultat[i].x);
    }
    qsort(rezultat,n,sizeof(Student),Compara_rezultat);
    for(i=0;i<n;i++)
    {
        fprintf(gis,"%s %d\n",rezultat[i].nume,rezultat[i].x);
    }
    free(rezultat);
}
int negativ(int el)
{
    if(el<0)
        return 1;
    else
        return 0;
}
void stergere(int *v,int *n,int(*negativ)(int))
{
    int i=0;
    for(i=0;i<*n;i++)
    {
        if(negativ(v[i])==1)
        {
            for(int j=i;j<(*n)-1;j++)
                v[j]=v[j+1];
            (*n)--;
        }
    }
}
void f2_2(FILE *fis,FILE *gis)
{
    int n=0,i=0;
    int *v=NULL;
    fscanf(fis,"%d",&n);
    v=(int*)malloc(n*sizeof(int*));
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
        fscanf(fis,"%d",&v[i]);
    stergere(v,&n,negativ);
    for(i=0;i<n;i++)
        fprintf(gis,"%d ",v[i]);
    fprintf(gis,"\n");
    free(v);
}
int Compara_vector(const void *el1,const void *el2)
{
    const float *a=(const float*)el1;
    const float *b=(const float*)el2;
    if(*a<*b)
        return -1;
    else
    {
        if(*a==*b)
            return 0;
        else
            return 1;
    }  
}
void f2_3(FILE *fis,FILE *gis)
{
    float *v=NULL;
    int n=0,i=0;
    fscanf(fis,"%d",&n);
    v=(float*)malloc(n*sizeof(float*));
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
        fscanf(fis,"%f",&v[i]);
    qsort(v,n,sizeof(float),Compara_vector);
    for(i=0;i<n;i++)
        fprintf(gis,"%0.2f ",v[i]);
    fprintf(gis,"\n");
    float x=0;
    float *ok=NULL;
    fscanf(fis,"%f",&x);
    ok=(float*)bsearch(&x,v,n,sizeof(float),Compara_vector);
    if(ok!=NULL)
        fprintf(gis,"DA\n");
    else
        fprintf(gis,"NU\n");
    free(v);
}
void tabelare(double a, double b,int n,double(*f)(double))
{
    int i=0;
    double s=0,x=0;
    s=(b-a)/n;
    for(i=0;i<=n;i++)
    {
        x=a+i*s;
        printf("%0.2lf %0.2lf\n",x,f(x));
    }
}
void f2_4(FILE *fis,FILE *gis)
{
    int n=0;
    double a=0,b=0;
    fscanf(fis,"%lf",&a);
    fscanf(fis,"%lf",&b);
    fscanf(fis,"%d",&n);
    //tabelare(-10,10,20,fabs);
    //tabelare(-10,10,20,sin);
    //tabelare(-10,10,20,cos);
    //tabelare(a,b,n,sin);
}
double functie1(double x)
{
    return (x*x*x+4)/(x*x+5);
}
double functie2(double x)
{
    return x+10;
}
double functie3(double x)
{
    return 2*x*x-1;
}
void Tabelare(double a,double b,double p,double(*f)(double),FILE *gis)
{
    double i=0;
    for(i=a;i<=b;i=i+p)
    {
        fprintf(gis,"%0.2lf %0.2lf\n",i,f(i));
    }
    fprintf(gis,"\n");
}
void s2_1(FILE *fis,FILE *gis)
{
    double a=0,b=0,p=0;
    fscanf(fis,"%lf",&a);
    fscanf(fis,"%lf",&b);
    fscanf(fis,"%lf",&p);
    double (*pf1)(double)=NULL,(*pf2)(double)=NULL,(*pf3)(double)=NULL;
    pf1=&functie1;
    pf2=&functie2;
    pf3=&functie3;
    Tabelare(a,b,p,pf1,gis);
    Tabelare(a,b,p,pf2,gis);
    Tabelare(a,b,p,pf3,gis);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Lab2.in","r");
    if(fis==NULL)
    {
        perror("eroare deschidere fisier intrare\n");
        exit(-1);
    }
    gis=fopen("Lab2.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier iesire\n");
        exit(-1);
    }
    //aplicatii laborator
    f2_1(fis,gis);
    f2_2(fis,gis);
    f2_3(fis,gis);
    f2_4(fis,gis);
    //probleme date la examen
    s2_1(fis,gis);

    return 0;
}