#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdint.h>

void ex4_2(FILE *fis1,FILE *gis1)
{
    int n=0,m=0,i=0,j=0;
    int **a=NULL;
    fscanf(fis1,"%d",&n);
    fscanf(fis1,"%d",&m);
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
                free(a[i]);
            exit(-1);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            fscanf(fis1,"%d",&a[i][j]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            fprintf(gis1,"%d ",a[i][j]);
        }
        fprintf(gis1,"\n");
    }
    fprintf(gis1,"\n");
    for(j=0;j<m;j++)
    {
        for(i=0;i<n;i++)
        {
            fprintf(gis1,"%d ",a[i][j]);
        }
        fprintf(gis1,"\n");
    }
    for(i=0;i<n;i++)
        free(a[i]);
    free(a);
}
void ex4_3(FILE *fis1,FILE *gis1)
{
    int i=0,argc=0;
    char *argv=NULL;
    for(i=0;i<)
}
int main(void)
{   
    FILE *fis1=NULL,*gis1=NULL;
    fis1=fopen("Lab5.in","r");
    if(fis1==NULL)
    {
        perror("eroare la deschiderea fisierului\n");
        exit(-1);
    }
    gis1=fopen("Lab5.out","w");
    if(gis1==NULL)
    {
        perror("eroare la deschiderea fisierului\n");
        exit(-1);
    }
    ex4_2(fis1,gis1);//EZ
    ex4_3(fis1,gis1);
    return 0;
}