#include <stdio.h>
#include <stdlib.h>

long long Ridicare_la_putere_in_timp_logaritmic(FILE *fis,FILE *gis)
{
    long long int n=0,p=0;
    long long int sol=1;
    const long long int MO=1999999973;
    fscanf(fis,"%lld",&n);//citim datele din fisier
    fscanf(fis,"%lld",&p);//n e numarul,p e exponentul puterii
    n=n%MO;
    while(p!=0)//am folosit algorimtul din curs iterativ pentru a avea o complexitate O(log p)
    {
        if(p%2==1)
        {
            sol=(sol*n)%MO;
        }
        n=(n*n)%MO;//actualizam baza
        p=p/2;
    }
    return (sol%MO);//returnam solutia problemei
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("lgput.in","r");//deschidem fisiere
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului de intrare\n");
        exit(-1);
    }
    gis=fopen("lgput.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului de iesire\n");
        exit(-1);
    }
    fprintf(gis,"%lld\n",Ridicare_la_putere_in_timp_logaritmic(fis,gis));//rezolvarea
    fclose(fis);//inchidem fisiere
    fclose(gis);

    return 0;
}