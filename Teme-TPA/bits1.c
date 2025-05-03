#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define SIZE 1000/8+1

void showBits8(uint8_t n,FILE *gis)
{
    int i=0;
    for(i=sizeof(n)*8-1;i>=0;i--)
    {
        fprintf(gis,"%d",(n>>i)&1);
    }
    fprintf(gis,"\n");
}
void setbit(int n,uint8_t *v,int m1,int m2)
{
    v[m1]=v[m1]|(1<<m2);
}
void citire(FILE *fis,uint8_t *v)
{   
    int n=0;
    while(fscanf(fis,"%d",&n)==1)
    {
        setbit(n,v,n/8,n%8);
    }
}
int main(void)
{   
    uint8_t *v=NULL;
    int i=0;
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("bits.in","r");
    if(fis==NULL)
    {
        perror("Eroare la deschidere fisier bits.in\n");
        exit(-1);
    }   
    v=(uint8_t*)calloc(SIZE,sizeof(uint8_t));
    if(v==NULL)
    {
        perror("Eroare la alocarea memoriei dinamice\n");
        exit(-1);
    }
    citire(fis,v);
    fclose(fis);
    gis=fopen("bits.out","w");
    if(gis==NULL)
    {
        perror("Eroare la deschidere fisier bits.out\n");
        exit(-1);
    }
    for(i=0;i<SIZE;i++)
    {
        showBits8(v[i],gis);
    }
    fclose(gis);
    free(v);

    return 0;   
}