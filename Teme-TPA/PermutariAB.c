#include <stdio.h>
#include <stdlib.h>

void Merge(long long int *a,long long int *b,long long int stanga,long long int mid,long long int dreapta,long long int *permutari)
{
    long long int st=0,dr=0,k=0;
    st=stanga;
    dr=mid+1;
    k=0;
    while(st<=mid&&dr<=dreapta)
    {
        if(b[st]<=b[dr])
        {
            a[k]=b[st];
            k++;
            st++;
        }
        else
        {       
            *permutari=*permutari+(mid-st+1);
            a[k]=b[dr];
            k++;
            dr++;
        }
    }
    while(st<=mid)
    {
        a[k]=b[st];
        k++;
        st++;
    }
    while(dr<=dreapta)
    {
        a[k]=b[dr];
        k++;
        dr++;
    }  
    for(long long int i=stanga;i<=dreapta;i++)
    {
        b[i]=a[i-stanga];
    }
}
void Mergesort(long long int *a,long long int *b,long long int stanga,long long int dreapta,long long int *permutari)
{
    long long int mid=0;
    if(stanga<dreapta)
    {
        mid=(stanga+dreapta)/2;
        Mergesort(a,b,stanga,mid,permutari);
        Mergesort(a,b,mid+1,dreapta,permutari);
        Merge(a,b,stanga,mid,dreapta,permutari);
    }
}
void citire(FILE *fis,FILE *gis)
{
    long long int n=0,*a=NULL,*b=NULL,permutari=0;
    fscanf(fis,"%lld",&n);
    a=(long long int*)malloc(n*sizeof(long long int));
    if(a==NULL)
    {
        perror("eroare la alocarea memoriei dinamic\n");
        exit(-1);
    }
    b=(long long int*)malloc(n*sizeof(long long int));
    if(b==NULL)
    {
        perror("eroare la alocarea memoriei dinamic\n");
        exit(-1);
    }
    long long int x=0;
    for(int i=0;i<n;i++)
    {
        fscanf(fis,"%lld",&x);
        a[x-1]=i;
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fis,"%lld",&x);
        b[i]=a[x-1];
    }
    Mergesort(a,b,0,n-1,&permutari);
    fprintf(gis,"%lld\n",permutari);
    free(a);
    free(b);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("permutariab.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    gis=fopen("permutariab.out","w");
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