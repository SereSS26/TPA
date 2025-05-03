#include <stdio.h>
#include <stdlib.h>

int valid1(int k,int *sol,int n)
{
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        if(sol[i]==1)
            j++;
    }
    if(j==k)
        return 1;
    else
        return 0;
}
int solutie1(int t,int n)
{
    if(t==n)
        return 1;
    else
        return 0;
}
void afis1(int *sol,int n,FILE *gis)
{
    for(int i=0;i<n;i++)
    {
        fprintf(gis,"%d",sol[i]);
    }
    fprintf(gis,"\n");
}
void back1(int n,int k,int *sol,FILE *gis,int t)
{   
    for(int i=0;i<n;i++)
    {   
        for(int j=0;j<9;j++)
        {
            sol[t]=j;
            if(valid1(k,sol,n))
            {
                if(solutie1(t+1,n))
                {
                    afis1(sol,n,gis);
                }
                else
                    back1(n,k,sol,gis,t+1);
            }
        }   
    }
}
void f12_1(FILE *fis,FILE *gis)
{
    int n=0,k=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&k);
    int sol[n];
    back1(n,k,sol,gis,0);
}
int valid2(int n,int *sol,int t)
{   
    int i=0;
    for(i=1;i<=n/2;i++)
    {   
        if(sol[i]>sol[i+1])
            return 0;
    }
    for(i=n/2+1;i<=n;i++)
    {
        if(sol[i]<sol[i+1])
            return 0;
    }
    return 1;
}
int solutie2(int t,int n)
{
    if(t==n)
        return 1;
    else
        return 0;
}
void afis2(int *sol,int n,FILE *gis)
{
    for(int i=1;i<=n;i++)
    {
        fprintf(gis,"%d",sol[i]);
    }
    fprintf(gis,"\n");
}
void back2(int n,int *sol,FILE *gis,int t)
{
    for(int i=1;i<=n;i++)
    {
        sol[t]=i;
        if(valid2(n,sol))
        {   
            printf("caca\n");
            if(solutie2(t,n))
            {
                afis2(sol,n,gis);
            }
            else
                back2(n,sol,gis,t+1);
        }
    }
}
void f12_2(FILE *fis,FILE *gis)
{
    int n=0;
    fscanf(fis,"%d",&n);
    int sol[n+1];
    back2(n,sol,gis,0);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Lab12.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschiderea fiserlui\n");
        exit(-1);
    }
    gis=fopen("Lab12.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierlui\n");
        exit(-1);
    }
    //f12_1(fis,gis);
    f12_2(fis,gis);
    fclose(fis);
    fclose(gis);

    return 0;
}