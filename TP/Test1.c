#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100
typedef struct
{
    unsigned int numar:4;
    unsigned int culoare:2;
}CARTE;
int compara1(const void *a, const void *b) {
    const CARTE *carteA = (const CARTE *)a;
    const CARTE *carteB = (const CARTE *)b;
    return carteA->numar - carteB->numar;
}
void t1(FILE *fis,FILE *gis)
{
    int i=0,j=0,k=0,n=0;
    int *v=NULL,**a=NULL;
    v=(int*)malloc(SIZE*sizeof(int));
    if(v==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    while(fscanf(fis,"%d",&n)==1)
    {
        if((k+1)%SIZE==0)
        {
            int *v2=NULL;
            v2=(int*)realloc(v,(k+1+SIZE)*sizeof(int));
            if(v2==NULL)
            {
                perror("eroare\n");
                exit(-1);
            }
            v=v2;
        }
        v[k]=n;
        k++;
    }
    n=k/2-1;
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        if(a[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(a[i]);
            free(a);
            perror("eroare\n");
            exit(-1);
        }
    }
    k=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=v[k];
            k++;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fprintf(gis,"%d ",a[i][j]);
        }
        fprintf(gis,"\n");
    }
    int k1=0,k2=n-1;
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<n;j++)
        {
            if(j>k1&&j<k2)
            {
                if(a[i][j]==0)
                    a[i][j]=1;
                else
                    if(a[i][j]==1)
                        a[i][j]=0;
            }
        }
        k1++;
        k2--;
    }
    fprintf(gis,"\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fprintf(gis,"%d ",a[i][j]);
        }
        fprintf(gis,"\n");
    }
    free(v);
    for(i=0;i<n;i++)
        free(a[i]);
    free(a);
}
void t2(FILE *fis,FILE *gis)
{
    CARTE *carte=NULL;
    carte=(CARTE*)malloc(5*sizeof(CARTE));
    if(carte==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    int aux=0;
    for(int i=0;i<5;i++)
    {   
        fscanf(fis,"%d",&aux);
        carte[i].numar=aux;
        fscanf(fis,"%d",&aux);
        carte[i].culoare=aux;
    }
    qsort(carte,5,sizeof(CARTE),compara1);
    for(int i=0;i<5;i++)
    {
        printf("%d %d\n",carte[i].numar,carte[i].culoare);
    }

}
int pf(int a)
{
    return a+1;
}
void f1(FILE *fis,FILE *gis)
{
    int i=0;
    int (*p)(int);
    p=&pf;
    int k=0;
    for(i=0;i<5;i++)
    {
        printf("%d %d\n",k,(*p)(k));
        k=k+1;
    }
}
int main(void)
{       
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("TEST1.in","r");
    if(fis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    gis=fopen("TEST1.out","w");
    if(gis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    //t1(fis,gis);
    //t2(fis,gis);
    f1(fis,gis);
    return 0;
}