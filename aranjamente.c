#include <stdio.h>
#include <stdlib.h>

int valid(int *sol,int t)
{
    int i=0;
    for(i=0;i<t;i++)
    {
        if(sol[t]<=sol[i])
            return 0;
    }
    return 1;
}
int solutie(int t,int k)
{
    if(t==k)
        return 1;
    else
        return 0;
}
void afis(int *sol,int k,FILE *gis)
{
    int i=0;
    for(i=0;i<k;i++)
    {
        fprintf(gis,"%d ",sol[i]);
    }
    fprintf(gis,"\n");
}
void back(int n,int k,int *v,int *sol,FILE *gis,int t)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        sol[t]=v[i];
        if(valid(sol,t))
        {       
            if(solutie(t+1,k))
            {
                afis(sol,k,gis);
            }
            else
                back(n,k,v,sol,gis,t+1);
        }
    }
}
void citire(FILE *fis,FILE *gis)
{
    int n=0,k=0,*v=NULL,*sol=NULL,i=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&k);
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    sol=(int*)malloc(k*sizeof(int));
    if(sol==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%d",&v[i]);
    }
    for(i=0;i<k;i++)
    {
        sol[i]=0;
    }
    back(n,k,v,sol,gis,0);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("a1.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    gis=fopen("a1.out","w");
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