#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void afisare(FILE *gis,int k,int *a)
{
    int i=0;
    for(i=0;i<k;i++)
    {
        fprintf(gis,"%d ",a[i]);
    }
    fprintf(gis,"\n");
}
void swap(int *a,int *b)
{
    int aux=0;
    aux=*a;
    *a=*b;
    *b=aux;
}
void combinari(FILE *gis,int poz,int n,int k,int *a)
{
    int i=0;
    if(poz==k)
    {
        afisare(gis,k,a);
    }
    for(i=poz;i<n;i++)
    {
        swap(&a[poz],&a[i]);
        combinari(gis,poz+1,n,k,a);
        swap(&a[poz],&a[i]);
    }

}
int main(void)
{       
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("combinari2.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului de intrare\n");
        exit(-1);
    }
    gis=fopen("combinari2.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului de iesire\n");
        exit(-1);
    }
    int n=0,k=0,*a=NULL;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&k);
    a=(int*)malloc(n*sizeof(int));
    if(a==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    int i=0;
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%d\n",&a[i]);
    }
    fclose(fis);
    combinari(gis,0,n,k,a);
    free(a);
    fclose(gis);

    return 0;
}