#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GMAX 10010

int maxim(int a,int b)//functie pentru a determina maximul
{
    if(a>b)
        return a;
    else
        return b;
}
int a[2][GMAX];//tablou cu doar doua linii,e suficient deoarece recurenta nu se foloseste decat de ultimile doua linii ale matricii
void rucsac(FILE *fis,FILE *gis)
{
    int n=0,g=0,i=0,*w=NULL,*p=NULL,l=0,j=0;
    fscanf(fis,"%d",&n);//numarul de obiecte ce se dau
    fscanf(fis,"%d",&g);//greutatea maximala 
    w=(int*)malloc((n+1)*sizeof(int));//vector pentru greutatile obiectelor
    if(w==NULL)
    {
        perror("eroare la alocarea dinamic\n");
        exit(-1);
    }
    p=(int*)malloc((n+1)*sizeof(int));//vector pentru preturile obiectelor
    if(p==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=1;i<=n;i++)//citim datele din fisier
    {
        fscanf(fis,"%d",&w[i]);
        fscanf(fis,"%d",&p[i]);
    }
    //l ne tine inte pe ce linie suntem,adica 0 sau 1/l e linia actuala
    //folosim programare dinamica
    for(i=1;i<=n;i++,l=1-l)
    {
        for(j=0;j<=g;j++)
        {
            a[1-l][j]=a[l][j];//copiem valorile precedente
            if(w[i]<=j)//daca un obiect respecta conditia putem sa-l adaugam in rucsac
            {   
                a[1-l][j]=maxim(a[1-l][j],(a[l][j-w[i]]+p[i]));//alegem valoarea maxima
            }
        }
    }
    fprintf(gis,"%d\n",a[l][g]);//valoarea maxima posibila in urma parcurgerii
    free(w);//eliberam memoria dinamica
    free(p);
}
int main(void)
{       
    clock_t start=clock();//start timp
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("rucsac.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    gis=fopen("rucsac.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    rucsac(fis,gis);//rezolvare
    fclose(fis);//inchidem fisiere
    fclose(gis);
    clock_t end=clock();//gata timp
    double timp=(double)(end-start)/CLOCKS_PER_SEC;
    printf("%lf\n",timp);//timp de executie

    return 0;
}