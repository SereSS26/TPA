#include <stdio.h>
#include <stdlib.h>

int valid(int *sol,int t)
{
    int i=0;
    for(i=0;i<t;i++)
    {
        if(sol[i]==sol[t])//intr-un aranjament elementele nu se pot repeta,deci trebuie sa fie distince
            return 0;
    }
    return 1;
}
int solutie(int t,int k)
{
    if(t==k)//daca lungimea unui aranjament este k,atunci am gasit o solutie
        return 1;
    else
        return 0;
}
void afis(int *sol,int k,FILE *gis)
{
    int i=0;
    for(i=0;i<k;i++)
    {
        fprintf(gis,"%d ",sol[i]);//scriem in fisier solutia gasita
    }
    fprintf(gis,"\n");
}
void back(int n,int k,int *v,int *sol,FILE *gis,int t)
{
    int i=0;
    for(i=0;i<n;i++)//algorimt de backtranking conform exemplului din curs
    {
        sol[t]=v[i];
        if(valid(sol,t))//functie valid
        {   
            if(solutie(t+1,k))//functie de verificare a solutiei
            {   
                afis(sol,k,gis);//functie de afisare
            }
            else
                back(n,k,v,sol,gis,t+1);//continuam generarea aranjamentelor
        }
    }
}
void citire(FILE *fis,FILE *gis)
{
    int n=0,k=0,*v=NULL,*sol=NULL;//n->numarul de elemente din multime,k->lungimea unui aranjament,v->vectorul multime,sol->solutia
    fscanf(fis,"%d",&n);//citim datele
    fscanf(fis,"%d",&k);
    v=(int*)malloc(n*sizeof(int));//alocam memorie dinamic pentru vectorul v
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    sol=(int*)malloc(k*sizeof(int));//alocam memorie dinamic pentru vectorul sol care are k elemente conform cerintei
    if(sol==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(int i=0;i<n;i++)
    {
        fscanf(fis,"%d",&v[i]);
    }
    back(n,k,v,sol,gis,0);//incepem genrarea aranjamentelor
    free(v);//eliberam memoriea alocata dinamic
    free(sol);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("aranjamente.in","r");//deschidem fisierul de intrare
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului de intrare\n");
        exit(-1);
    }
    gis=fopen("aranjamente.out","w");//deschidem fisierul de iesire
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului de iesire\n");
        exit(-1);
    }
    citire(fis,gis);//functie de citire a datelor problemei
    fclose(fis);//inchidem fisierele
    fclose(gis);

    return 0;
}