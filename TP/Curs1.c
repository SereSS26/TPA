#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <string.h>
#define INFININT 0xFFFFFFF
void eliberare_linii(int **a,int n)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        free(a[i]);
    }
}
void ex1_curs(int n,int m,FILE *fis,FILE *gis)
{
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    int i=0,j=0,**a=NULL;
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("Eroare la alocare memorie\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(m*sizeof(int));
        if(a[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(a[j]);
            perror("Eroare la alocarea memoriei\n");
            exit(-1);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(i>=j)
                a[i][j]=i;
            else
                a[i][j]=j;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fprintf(gis,"%d ",a[i][j]);
        }
        fprintf(gis,"\n");
    }
    eliberare_linii(a,n);
    free(a);
}
void ex2_curs(int n,int m,FILE *fis,FILE *gis)
{
    fscanf(fis,"%d",&n);
    int i=0,j=0,**a=NULL;
    a=(int**)malloc(n*sizeof(int*));
    if(a==NULL)
    {
        perror("Eroare la alocarea memoriei\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        a[i]=(int*)malloc(n*sizeof(int));
        if(a[i]==NULL)
        {
            for(j=0;j<i;j++)
                free(a[j]);
            perror("Eroare la alocarea memoriei\n");
            exit(-1);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i<j)
                fscanf(fis,"%d",&a[i][j]);
            if(i==j)
                a[i][j]=0;
            if(i>j)
                a[i][j]=a[j][i];
        }
    }
    /*
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    */
    int mini=INFININT,ii=0,jj=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(a[i][j]<mini&&a[i][j]!=0)
            {
                mini=a[i][j];
                ii=i;
                jj=j;
            }
    }
    fprintf(gis,"%d %d %d\n",mini,ii,jj);
    eliberare_linii(a,n);
    free(a);
}
void f1(int n,FILE *fis,FILE *gis)
{
    fscanf(fis,"%d",&n);
    int a[n][n],c[n],l[n];
    int i=0;
    int *p=NULL;
    for(i=0;i<n;i++)
    {
        l[i]=0;
        c[i]=0;
    }
    for(p=&a[0][0];p<&a[n][0];++p) 
    {
        fscanf(fis,"%d",p);
    }
    for(i=0;i<n;i++)
    {
        for(p=&a[i][0];p<&a[i][n];++p)
            l[i]=l[i]+(*p);
    }
    for(i=0;i<n;i++)
    {
        for(p=&a[0][0]+i;p<&a[n][0]+i*(n-1);p=p+n)
            c[i]=c[i]+(*p);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",l[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("%d\n",c[i]);
    }
}
int inmat(int t,int n)
{
    if(t>n-1||t<0)
        return 0;
    else
        return 1;
}
void orizontal(char **a,int i,int j,int n,char *cuv)
{
    int k=0,ok=1;
    int t=j;
    for(k=0;k<strlen(cuv);k++)
    {   
        if(inmat(t,n)==0)
        {
            ok=0;
            break;
        }
        if(cuv[k]!=a[i][t])
            ok=0;
        t++;
    }
    if(ok==1)
    {
        printf("De la linia %d,coloana %d spre dreapta\n",i,j);
    }
    t=j;
    ok=1;
    for(k=0;k<strlen(cuv);k++)
    {   
        if(inmat(t,n)==0)
        {
            ok=0;
            break;
        }
        if(cuv[k]!=a[i][t])
            ok=0;
        t--;
    }
    if(ok==1)
    {
        printf("De la linia %d,coloana %d spre stanga\n",i,j);
    }
}
void vertical(char **a,int i,int j,int n,char *cuv)
{
    int ok=1,k=0;
    int t=i;
    for(k=0;k<strlen(cuv);k++)
    {   
        if(inmat(t,n)==0)
        {
            ok=0;
            break;
        }
        if(cuv[k]!=a[t][j])
        {
            ok=0;
        } 
        t++;
    }
    if(ok==1)
    {
        printf("De la linia %d,coloana %d in jos\n",i,j);
    }
    t=i;
    ok=1;
    for(k=0;k<strlen(cuv);k++)
    {
        if(inmat(t,n)==0)
        {
            ok=0;
            break;
        }
        if(cuv[k]!=a[t][j])
            ok=0;
        t--;
    }
    if(ok==1)
    {
        printf("De la linia %d,coloana %d in sus\n",i,j);
    }
}
void f2(int n,FILE *fis,FILE *gis)
{
    fscanf(fis,"%d",&n);
    char **a=NULL;
    a=(char**)malloc(n*sizeof(char*));
    if(a==NULL)
    {
        perror("Eroare la alocare memorie\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        a[i]=(char*)malloc(n*sizeof(int));
        if(a[i]==NULL)
        {
            for(int j=0;j<i;j++)
                free(a[i]);
            perror("Eroare la alocarea memoriei\n");
            exit(-1);
        }
    }
    int i=0,j=0;
    char c=0,cuv[256];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            c=fgetc(fis);
            if(c=='\n'||c==' ')
            {   
                j--;
                continue;
            }
            a[i][j]=c;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%c ",a[i][j]);
        printf("\n");
    }
    fscanf(fis,"%255s",cuv);
    printf("%s\n",cuv);
    if(strlen(cuv)>n)
    {
        printf("Dimenisune cuvant prea mare\n");
    }
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                orizontal(a,i,j,n,cuv);
                vertical(a,i,j,n,cuv);
            }
        }
    }
    for(i=0;i<n;i++)
        free(a[i]);
    free(a);
}
int main(void)
{       
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("file1.in","r");
    if(fis==NULL)
    {
        perror("Eroare deschidere fisier file1.in\n");
        exit(-1);
    }
    gis=fopen("file1.out","w");
    if(gis==NULL)
    {
        perror("Eroare la deschidere fisier file1.out\n");
        exit(-1);
    }
    int n=0,m=0;
    fprintf(gis,"Exercitii din curs1\n");
    ex1_curs(n,m,fis,gis);
    ex2_curs(n,m,fis,gis);
    fprintf(gis,"Exercitii din TEMA\n");
    f1(n,fis,gis);
    f2(n,fis,gis);
    fclose(fis);
    fclose(gis);
    
    return 0;
}