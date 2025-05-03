#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void afisare_matrice(int **a,int n,int m)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}
void f8_1(FILE *fis,FILE *gis)
{
    int n=0,i=0,j=0;
    int **a=NULL;
    fscanf(fis,"%d",&n);
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        printf("eroare la alocare memeorie\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        if(a[i]==NULL)
        {
            for(int j=0;j<i;j++)
                free(a[j]);
            free(a);
            printf("eroare la alocare memroeie\n");
            exit(-1);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            fscanf(fis,"%d",&a[i][j]);
    }
    afisare_matrice(a,n,n);
    int ok=1;
    int fr=n*n-n;
    for(i=0;i<n;i++)
    {
        if(a[i][i]!=1)  
            ok=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(a[i][j]==0)
                fr--;
    }
    if(fr!=0)
        ok=0;
    if(ok==1)
        fprintf(gis,"DA\n");
    else
        fprintf(gis,"NU\n");
    for(i=0;i<n;i++)
        free(a[i]);
    free(a);
}
void f8_2(FILE *fis,FILE *gis)
{
    int i=0,j=0,n=0,m=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    int a[10][10];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            if(i>=j)
                a[i][j]=i;
            else
                a[i][j]=j;
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void f8_3(FILE *fis,FILE *gis)
{
    int **a=NULL;
    int i=0,j=0,n=0,m=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("eroare la alocarea dinmaica\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(m*sizeof(int));
        if(a[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(a[j]);
            free(a);
            perror("eroare la alocarea dinamica a memoriei\n");
            exit(-1);
        }
    }
    int *p=NULL;
    int nr=0;
    p=&a[0][0];
    for(p=&a[0][0];p<&a[0][0]+n*n;p++)
    {   
        nr++;
        (*p)=nr;
    }
    printf("\n");
    for(int i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}
void f8_4(FILE *fis,FILE *gis)
{
    int n=0,i=0,j=0;
    int a[50][50];
    fscanf(fis,"%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            fscanf(fis,"%d",&a[i][j]);
        }
    }
    int k=1,aux=0;
    for(i=0;i<n;i++)
    {
        for(j=k;j<n;j++)
        {
            aux=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=aux;
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
}
void f8_5(FILE *fis,FILE *gis)
{
    int a[50][50];
    int l[50],c[50],n=0,i=0,j=0;
    int *p1=NULL,*p2=NULL,*p3=NULL;
    fscanf(fis,"%d",&n);
    for(p1=l;p1<l+n;p1++)
        *p1=0;
    for(p2=c;p2<c+n;p2++)
        *p2=0;
    for(p3=&a[0][0];p3<(&a[0][0])+n*n;p3++)
        fscanf(fis,"%d",p3);
    for(p3=&a[0][0];p3<(&a[0][0])+n*n;p3++)
    {
        i = (p3 - &a[0][0]) / n;
        j = (p3 - &a[0][0]) % n;
        l[i] =l[i]+ (*p3); 
        c[j] =c[j]+ (*p3);
    }
    fprintf(gis, "Suma elementelor de pe fiecare linie:\n");
    for (int *p1 = l; p1 < l + n; p1++)
        fprintf(gis, "%d ", *p1);
    fprintf(gis, "\n");

    fprintf(gis, "Suma elementelor de pe fiecare coloana:\n");
    for (int *p2 = c; p2 < c + n; p2++)
        fprintf(gis, "%d ", *p2);
    fprintf(gis, "\n");
}
void exemplu(FILE *fis,FILE *gis)
{
    double **a=NULL;
    int i=0,j=0,n=0,m=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    a=(double**)malloc(n*sizeof(double*));
    if(a==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(double*)malloc(m*sizeof(double));
        if(a[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(a[j]);
            free(a);
            perror("eroare la alocarea dinamica amemoreoi\n");
            exit(-1);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            a[i][j]=((double)(i+j))/2;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fprintf(gis,"%0.2lf ",a[i][j]);
        }
        fprintf(gis,"\n");
    }
    for(i=0;i<n;i++)
        free(a[i]);
    free(a);
}
int verificare(int **a,int **b,int n,int m,int i,int j)
{
    int k=0,t=0,ok=1;
    for(k=0;k<m;k++)
    {
        for(t=0;t<m;t++)
        {
            if(a[i+k][j+t]!=b[k][t])
                ok=0;
        }
    }
    return ok;
}
void subiect8_1(FILE *fis,FILE *gis)
{
    int n=0,m=0,i=0,j=0,ok=0;
    int **a=NULL,**b=NULL;
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
        a[i]=(int*)malloc(n*sizeof(int));
        if(a[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(a[i]);
            free(a);
            perror("eroare la alocarea dinamica\n");
            exit(-1);
        }
    }
    b=(int**)malloc(m*sizeof(int*));
    if(b==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=0;i<m;i++)
    {
        b[i]=(int*)malloc(m*sizeof(int));
        if(b[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(b[i]);
            free(b);
            perror("eroare la alocarea dinamica\n");
            exit(-1);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            fscanf(fis,"%d",&a[i][j]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            fscanf(fis,"%d",&b[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i+m<=n&&j+m<=n)
            {
                ok=verificare(a,b,n,m,i,j);
                if(ok==1)
                {   
                    printf("(%d %d)\n",i,j);
                    ok=0;
                }
            }   
        }
    }
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Lab1.in","r");
    if(fis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    gis=fopen("Lab1.out","w");
    if(gis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    f8_1(fis,gis);
    exemplu(fis,gis);
    f8_2(fis,gis);
    f8_3(fis,gis);
    f8_4(fis,gis);
    f8_5(fis,gis);
    //restul din laborator par simple sau asemanatoare cu ce am facut mai sus
    subiect8_1(fis,gis);//relativ simplu pt examen
    //pe urmatorul l-am facut la curs1
    fclose(fis);
    fclose(gis);
    return 0;
}