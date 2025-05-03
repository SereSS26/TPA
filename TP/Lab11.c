#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int x;
    int y;
}Gaura;
void f10_1(FILE *fis,FILE *gis)
{
    int n=0,x1=0,y1=0,i=0,j=0,m=0;
    Gaura *gaura=NULL;
    fscanf(fis,"%d",&n);
    gaura=(Gaura*)malloc(n*sizeof(Gaura));
    if(gaura==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%d",&x1);
        fscanf(fis,"%d",&y1);
        gaura[i].x=x1;
        gaura[i].y=y1;
    }
    x1=0;
    y1=0;
    int *v=NULL;
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        v[i]=0;
    }
    m=n;
    while(m!=0)
    {   
        int mini=999999999;
        int cur=0;
        for(i=0;i<n;i++)
        {
            if(v[i]==0)
            {
                cur=sqrt((x1-gaura[i].x)*(y1-gaura[i].y));
            }
            if(cur<mini&&v[i]==0)
            {
                mini=cur;
                j=i;
            }   
        }
        v[j]=1;
        x1=gaura[j].x;
        y1=gaura[j].y;
        fprintf(gis,"%d %d\n",x1,y1);
        m--;
    }
}
void f10_2(FILE *fis,FILE *gis)
{   
    double n,ma,mb,m,d;
    fscanf(fis,"%lf",&n);
    fscanf(fis,"%lf",&ma);
    fscanf(fis,"%lf",&mb);
    fscanf(fis,"%lf",&m);
    fscanf(fis,"%lf",&d);
    double forta=0,g=10;
    double pas=d/n,i=0;
    for(i=0;i<d;i=i+pas)
    {
        forta=(g*mb*m)/((d-i)*(d-i))-(g*ma*m)/(i*i);
        fprintf(gis,"%lf\n",forta);
    }
}
void f10_3(FILE *fis,FILE *gis)
{
    int n=0,m=0,**a=NULL,i=0,j=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(m*sizeof(int));
        if(a[i]==NULL)
        {
            perror("eroare la alocarea dinamica\n");
            for(j=0;j<i;j++)
            {
                free(a[j]);
            }
            free(a);
            exit(-1);
        }
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            fscanf(fis,"%d",&a[i][j]);
    //? nu e clara cerinta ?
}
typedef struct
{
    char nume[20];
    int valoare;
}Jucator;
int compara(const void *a,const void *b)
{
    Jucator *jucatorA=(Jucator *)a;
    Jucator *jucatorB=(Jucator *)b;
    return jucatorB->valoare-jucatorA->valoare;
}
void f10_4(FILE *fis,FILE *gis)
{
    Jucator *jucator=NULL;
    int n=0,m=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    jucator=(Jucator*)malloc(n*sizeof(Jucator));
    if(jucator==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fis,"%19s",jucator[i].nume);
        fscanf(fis,"%d",&jucator[i].valoare);
    }
    qsort(jucator,n,sizeof(Jucator),compara);
    int *v=NULL;
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    //...
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Lab11.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului\n");
        exit(-1);
    }
    gis=fopen("Lab11.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fiserului\n");
        exit(-1);
    }
    f10_1(fis,gis);
    f10_2(fis,gis);
    f10_3(fis,gis);
    f10_4(fis,gis);
    fclose(fis);
    fclose(gis);

    return 0;
}