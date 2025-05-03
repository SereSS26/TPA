#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afisare(int *tabla_sah,int n)
{   
    int linie=0,coloana=0;
    for(linie=0;linie<n;linie++) 
    {
        for(coloana=0;coloana<n;coloana++) 
        {
            if(tabla_sah[linie]==coloana) 
            {
                printf("X ");
            } 
            else 
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}
int valid(int *tabla_sah,int linie, int coloana) 
{   
    int poz=0;
    for(poz=0;poz<linie;poz++) 
    {
        if (tabla_sah[poz]==coloana || abs(tabla_sah[poz]-coloana)==abs(poz-linie))
        {
            return 0;
        }
    }
    return 1;
}
void dame(int coloana,int n,int *tabla_sah,int *nr)
{   
    int linie=0;
    if(coloana==n)
    {   
        (*nr)++;
        afisare(tabla_sah,n);
    }
    for(linie=0;linie<n;linie++)
    {
        if(valid(tabla_sah,coloana,linie)==1)
        {
            tabla_sah[coloana]=linie;
            dame(coloana+1,n,tabla_sah,nr);
        }
        else
        {
            continue;
        }
    }
}
int main(void)
{       
    FILE *fis=NULL;
    fis=fopen("dame.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    int n=0,nr=0;
    fscanf(fis,"%d",&n);
    int *tabla_sah=NULL;
    tabla_sah=(int*)malloc((n)*sizeof(int));
    if(tabla_sah==NULL)
    {
        perror("eroare la alocarea dinamica a memroiei\n");
        exit(-1);
    }
    fclose(fis);
    memset(tabla_sah,-1,n*sizeof(int));
    dame(0,n,tabla_sah,&nr);
    free(tabla_sah);
    printf("%d\n",nr);

    return 0;
}