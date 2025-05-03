#include <stdio.h>
#include <stdlib.h>

int valid(int *sol,int t)
{
    int i=0;
    for(i=0;i<t;i++)
    {
        if(sol[t]<=sol[i])//intr-o combinare elemtele trebuie sa fie distince si in ordine crescatoare(pentru a evita generarea de aranjamente in schimb)
            return 0;
    }
    return 1;
}
int solutie(int t,int k)
{
    if(t==k)//daca lungimea ajunge sa fie k,am gasit o combinare
        return 1;
    else
        return 0;
}
void afis(int *sol,int k,FILE *gis)
{
    int i=0;
    for(i=0;i<k;i++)
    {
        fprintf(gis,"%d ",sol[i]);//afisam solutia
    }
    fprintf(gis,"\n");
}
void back(int n,int k,int *v,int *sol,FILE *gis,int t)
{
    int i=0;
    for(i=0;i<n;i++)//folosim alogorimul de backtraking din curs
    {
        sol[t]=v[i];
        if(valid(sol,t))//functie valid
        {       
            if(solutie(t+1,k))//functie de verifcarea a solutiei
            {
                afis(sol,k,gis);//functie de afisare
            }
            else
                back(n,k,v,sol,gis,t+1);//continuam generarea combinarilor
        }
    }
}
void citire(FILE *fis,FILE *gis)
{
    int n=0,k=0,*v=NULL,*sol=NULL,i=0;//n->numarul elemtelor multimii,k->lungimea unei combinari,v->vectorul multime,sol->solutia
    fscanf(fis,"%d",&n);//citim datele din fiser
    fscanf(fis,"%d",&k);
    v=(int*)malloc(n*sizeof(int));//alocam memorie dinamic pentru vectorul v
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    sol=(int*)malloc(k*sizeof(int));//alocam memorie dinamic pentru vectorul sol,care va avea k elemente
    if(sol==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%d",&v[i]);
    }
    back(n,k,v,sol,gis,0);//incepem generarea combinarilor
    free(v);//eliberam memoria alocata dinamic
    free(sol);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("combinari.in","r");//deschidem fiser de intrare
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    gis=fopen("combinari.out","w");//deschidem fisier de iesire
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier\n");
        exit(-1);
    }
    citire(fis,gis);//functie de citire a datelor problemei
    fclose(fis);//inchidem fisierele
    fclose(gis);

    return 0;
}