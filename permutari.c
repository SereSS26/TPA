#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void citire(FILE *fis,uint32_t *n,uint32_t **a)
{
    fscanf(fis,"%u",n);
    *a=(uint32_t*)malloc((*n)*sizeof(uint32_t));
    if(*a==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    for(int i=0;i<(*n);i++)
    {
        fscanf(fis,"%u",&(*a)[i]);
    }
}
void swap(uint32_t *a,uint32_t *b) 
{
    uint32_t aux=0;
    aux=(*a);
    (*a)=(*b);
    (*b)=aux;
}
void afisare(FILE *gis,uint32_t *a,uint32_t n) 
{
    for(int i=0;i<n;i++) 
    {
        fprintf(gis,"%u ",a[i]);
    }
    fprintf(gis,"\n");
}

void permutari(FILE *gis,uint32_t *a,uint32_t start,uint32_t n) 
{
    if(start==n-1) 
    {
        afisare(gis,a,n);
    }
    for(int i=0;i<n;i++) 
    {
        printf("%u ",a[i]);
    }
    printf("\n");
    for(uint32_t i=start;i<n;i++) 
    {
        swap(&a[start],&a[i]);
        permutari(gis,a,start+1,n);
        printf("%d   \n",start);
        swap(&a[start],&a[i]);
    }
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("permutari.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier intrare\n");
        exit(-1);
    }
    gis=fopen("permutari.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier iesire\n");
        exit(-1);
    }
    uint32_t n=0;
    uint32_t *a=NULL;
    citire(fis,&n,&a);
    permutari(gis,a,0,n);
    free(a);

    return 0;
}