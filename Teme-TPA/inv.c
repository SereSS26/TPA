#include <stdio.h>
#include <stdlib.h>
#define MO 9917

void Merge(int *v,int *aux,int stanga,int mid,int dreapta,int *inversiuni)
{
    int st=0,dr=0,k=0;
    st=stanga;
    dr=mid+1;
    k=0;
    while(st<=mid&&dr<=dreapta)
    {
        if(v[st]<=v[dr])
        {
            aux[k]=v[st];
            k++;
            st++;
        }
        else
        {
            *inversiuni=(*inversiuni+(mid-st+1))%MO;
            aux[k]=v[dr];
            k++;
            dr++;
        }
    }
    while(st<=mid)
    {
        aux[k]=v[st];
        k++;
        st++;
    }
    while(dr<=dreapta)
    {
        aux[k]=v[dr];
        k++;
        dr++;
    }  
    for(int i=stanga;i<=dreapta;i++)
    {
        v[i]=aux[i-stanga];
    }
}
void Mergesort(int *v,int *aux,int stanga,int dreapta,int *inversiuni)
{
    int mid=0;
    if(stanga<dreapta)
    {
        mid=(stanga+dreapta)/2;
        Mergesort(v,aux,stanga,mid,inversiuni);
        Mergesort(v,aux,mid+1,dreapta,inversiuni);
        Merge(v,aux,stanga,mid,dreapta,inversiuni);
    }
}
void citire(FILE *fis,FILE *gis)
{
    int n=0,*v=NULL,*aux=NULL,i=0,inversiuni=0;
    fscanf(fis,"%d",&n);
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%d",&v[i]);
    }
    aux=(int*)malloc(n*sizeof(int));
    if(aux==NULL)
    {
        perror("eroare la alocarea memoriei dinamice\n");
        exit(-1);
    }
    Mergesort(v,aux,0,n-1,&inversiuni);
    fprintf(gis,"%d\n",inversiuni);
    free(v);
    free(aux);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("inv.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    gis=fopen("inv.out","w");
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