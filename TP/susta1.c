#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

void f8_3(FILE *fis,FILE *gis)
{   
    fprintf(gis,"\n");
    int **a=NULL,n=0,m=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("eroare la alocarea dinamica a matricilor\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        a[i]=(int*)malloc(m*sizeof(int));
        if(a[i]==NULL)
        {
            for(int j=0;j<i;j++)
                free(a[j]);
            free(a);
            perror("eroare la alocarea dinamica\n");
            exit(-1);
        }
    }
    int *p=NULL;
    int k=1;
    int t=0;
    while(t!=n)
    {
    for(p=&(a[t][0]);p<=(&a[t][m-1]);p++)
    {
        *p=k;
        k++;
    }
    t++;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            fprintf(gis,"%d ",a[i][j]);
        fprintf(gis,"\n");
    }
    for(int i=0;i<n;i++)
        free(a[i]);
    free(a);
    fprintf(gis,"\n");
}
void f8_4(FILE *fis,FILE *gis)
{
    int **a=NULL,n=0,i=0,j=0;
    fscanf(fis,"%d",&n);
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("eroare la alocarea memoriei\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        if(a[i]==NULL)
        {
            perror("eroare la alocarea memeoriei\n");
            for(j=0;j<i;j++)
                free(a[j]);
            free(a);
            exit(-1);
        }
    }
    int k=1;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            {
                a[i][j]=k;
                k++;
            }
    }
    int aux=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            aux=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=aux;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            fprintf(gis,"%d ",a[i][j]);
        fprintf(gis,"\n");
    }
    fprintf(gis,"\n");
}
void f8_5(FILE *fis,FILE *gis)
{   
    int n=0,m=0,i=0,j=0,**a=NULL;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("eroare la alocarea dinamica a matriceii\n");
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
            perror("erpoare\n");
            exit(-1);
        }
    }
    int *p=NULL,*p1=NULL,*p2=NULL;
    p1=(int*)malloc(n*sizeof(int));
    p2=(int*)malloc(m*sizeof(int));
    int k=1,t=0,kk=0;
    while(t!=n)
    {   
        kk=0;
        for(p=&a[t][0];p<=&a[t][m-1];p++)
        {
            *p=k;
            k++;
            p1[t]=p1[t]+(*p);
            p2[kk]=p2[kk]+(*p);
            kk++;
        }
        t++;
    }
    for(i=0;i<n;i++)
        fprintf(gis,"%d ",p1[i]);
    fprintf(gis,"\n");
    for(i=0;i<m;i++)
        fprintf(gis,"%d ",p2[i]);
    fprintf(gis,"\n");
    fprintf(gis,"\n");
}
void f8_8(FILE *fis,FILE *gis)
{
    int n=0,m=0,p=0,**a1=NULL,**a2=NULL,**a3=NULL;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    fscanf(fis,"%d",&p);
    a1=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        a1[i]=(int*)malloc(m*sizeof(int));
    a2=(int**)malloc(m*sizeof(int*));
    for(int i=0;i<m;i++)
        a2[i]=(int*)malloc(p*sizeof(int));
    a3=(int**)malloc(n*sizeof(int*));
    for(int i=0;i<n;i++)
        a3[i]=(int*)malloc(p*sizeof(int));
    int k=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            a1[i][j]=k;
            k++;
        }
    }
    k=1;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<p;j++)
        {
            a2[i][j]=k;
            k++;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            a3[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int t=0;t<p;t++)
            {
                a3[i][t]=a3[i][t]+a1[i][j]*a2[j][t];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
            fprintf(gis,"%d ",a3[i][j]);
        fprintf(gis,"\n");
    }
    fprintf(gis,"\n");
}
int verificare(int **a1,int **a2,int x,int y,int m,int n)
{   
    int ok=1,i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            {   
                if(a2[i][j]!=a1[i+x][j+y]&&(i+x)<n&&(j+y)<n)
                    ok=0;
            }
    }
    return ok;
}
void s8_1(FILE *fis,FILE *gis)
{
    int n=0,m=0,**a1=NULL,**a2=NULL;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    int i=0,j=0;
    a1=(int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        a1[i]=(int*)malloc(n*sizeof(int));
    }
    a2=(int**)malloc(m*sizeof(int*));
    for(i=0;i<m;i++)
    {
        a2[i]=(int*)malloc(m*sizeof(int));
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            fscanf(fis,"%d",&a1[i][j]);
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
            fscanf(fis,"%d",&a2[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a1[i][j]==a2[0][0]&&((n-i)>=m)&&((n-j)>=m))
                if(verificare(a1,a2,i,j,m,n)==1)
                    fprintf(gis,"%d %d\n",i,j);
        }
    }
    fprintf(gis,"\n");
}

int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("susta1.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului\n");
        exit(-1);
    }
    gis=fopen("susta1.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului\n");
        exit(-1);
    }
    fprintf(gis,"LABORATOR1\n");
    f8_3(fis,gis);
    f8_4(fis,gis);
    f8_5(fis,gis);
    f8_8(fis,gis);
    s8_1(fis,gis);
    fprintf(gis,"LABORATOR2\n");
    
    fclose(fis);
    fclose(gis);

    return 0;
}