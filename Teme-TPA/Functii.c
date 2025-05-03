#include <stdio.h>
#include <stdlib.h>
#define M 30103

int Ridicare_la_putere_logaritmic(int n,int p)//algorimul de ridicare la putere iterativ din curs cu complexitate O(log p)
{
    int sol=1;
    while(p!=0) 
    {
        if(p%2==1) 
        {
            sol=(sol*n)%M;
        }
        n=(n*n)%M;
        p=p/2;
    }
    return sol;//returnam solutia
}
void functii(FILE *fis,FILE *gis)
{
    int n=0,s=0,i=0,u=1,v=1;
    fscanf(fis,"%d",&n);//citim din fisier n si s cu senificatia din cerinta
    fscanf(fis,"%d",&s);
    for(i=1;i<=s;i++) 
    {
        u=(u*i)%M;//calculam valoarea lui u care va fi s factorial
    }
    for(i=n-s+1;i<=n;++i) 
    {
        v=(v*i)%M;//v reprezinta produsul elementelor de la n-s+1 la n
    }
    fprintf(gis,"%d\n",((v*Ridicare_la_putere_logaritmic(u,M-2)%M)*(Ridicare_la_putere_logaritmic(2,s)-2))%M);//conform teoremei lui fermat
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("functii.in","r");//deschidem fisierele
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului de intrare\n");
        exit(-1);
    }
    gis=fopen("functii.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului de iesire\n");
        exit(-1);
    }
    functii(fis,gis);//rezolvarea
    fclose(fis);//inchidem fisierele
    fclose(gis);
    
    return 0;
}