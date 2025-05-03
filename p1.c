#include <stdio.h>
#include <stdlib.h>

int valid(int *sol,int k)
{
    for(int i=0;i<k;i++)
    {
        if(sol[k]==sol[i])
            return 0;
    }
    return 1;
}
int solutie(int n,int k)
{
    if(k==n)
        return 1;
    else
        return 0;
}
void afis(int n,int *sol,FILE *gis)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        fprintf(gis,"%d ",sol[i]);
    }
    fprintf(gis,"\n");
}
void back(int n,int *v,int *sol,FILE *gis,int k)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        sol[k]=v[i];
        if(valid(sol,k))
        {   
            if(solutie(k+1,n))
            {
                afis(n,sol,gis);
            }
            else
                back(n,v,sol,gis,k+1);
        }
    }
}
void citire(FILE *fis,FILE *gis)
{
    int n=0,*v=NULL,*sol=NULL;
    fscanf(fis,"%d",&n);
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    sol=(int*)malloc(n*sizeof(int));
    if(sol==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
        sol[i]=0;
    for(int i=0;i<n;i++)
    {
        fscanf(fis,"%d",&v[i]);
    }
    back(n,v,sol,gis,0);
    free(v);
    free(sol);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("p1.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    gis=fopen("p1.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    citire(fis,gis);
    fclose(fis);
    fclose(gis);
    
    return 0;
}