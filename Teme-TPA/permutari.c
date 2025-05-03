#include <stdio.h>
#include <stdlib.h>

int valid(int *sol,int k)
{
    for(int i=0;i<k;i++)
    {
        if(sol[k]==sol[i])//intr-o permutare elementele nu se pot repeta,deci trebuie sa fie diferite
            return 0;
    }
    return 1;
}
int solutie(int n,int k)
{
    if(k==n)//daca atingem numarul necesar de elemente ale unei permutari am gasit o solutie
        return 1;
    else
        return 0;
}
void afis(int n,int *sol,FILE *gis)
{
    int i=0;
    for(i=0;i<n;i++)
    {
        fprintf(gis,"%d ",sol[i]);//scriem permutarea gasita in fisier
    }
    fprintf(gis,"\n");
}
void back(int n,int *v,int *sol,FILE *gis,int k)
{
    int i=0;
    for(i=0;i<n;i++)//algorimt clasic de backtraking dupa modelul din curs
    {
        sol[k]=v[i];
        if(valid(sol,k))//functia valid
        {   
            if(solutie(k+1,n))//functia de verificare a solutiei
            {
                afis(n,sol,gis);//functie de afisare a solutiei
            }
            else
                back(n,v,sol,gis,k+1);//continuam generarea permutarilor
        }
    }
}
void citire(FILE *fis,FILE *gis)
{
    int n=0,*v=NULL,*sol=NULL;//n->numarul elementelor din multime,v->vectorul multime,sol->vectorul solutie
    fscanf(fis,"%d",&n);
    v=(int*)malloc(n*sizeof(int));//alocam memorie dinamic pentru vectorul multime
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    sol=(int*)malloc(n*sizeof(int));//alocam memorie dinamica pentru vectorul solutie,o solutie va avea n elemente
    if(sol==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fis,"%d",&v[i]);
    }
    back(n,v,sol,gis,0);//incepem generarea permutarilor folosind metoda backtraking
    free(v);//eliberam memoria alocata dinamic
    free(sol);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("permutari.in","r");//deschidem fisier intrare
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier intrare\n");
        exit(-1);
    }
    gis=fopen("permutari.out","w");//deschidem fisier iesire
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier iesire\n");
        exit(-1);
    }
    citire(fis,gis);//functie de citire a datelor problemei
    fclose(fis);//inchidem fisierele
    fclose(gis);
    
    return 0;
}