#include <stdio.h>
#include <stdlib.h>

long Help_Mike(FILE *fis)
{   
    long nr=0,n=0,k=0,*a=NULL;
    fscanf(fis,"%ld",&n);//citim numerele n si k cu semnificatia din enunt
    fscanf(fis,"%ld",&k);
    a=(long*)calloc(k,sizeof(long));//alocam memorie dinamica pentru vectorul a
    if(a==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    for(long i=1;i<=n;i++)
    {
        a[i%k]++;//calculam freceventele resturilor numerelor din multime la k
    }
    nr=nr+(a[0]*(a[0]-1))/2;//calculam numarul de perechi de tip a)
    for(long i=1;i<(k+1)/2;i++)
    {
        if(i!=k-1)
            nr=nr+(a[i]*a[k-i]);//calculam numarul de perechi de tip b)
    }
    if(k%2==0)
    {
        nr=nr+(a[k/2]*(a[k/2]-1))/2;//daca k-par calculam numarul de perechi c)
    }
    free(a);//eliberam memoria alocata dinamic
    return nr;//returnam raspunsul fiecarei intrebari
}
/*
OBS:
->Trebuie sa gasim perechi(i,j) cu i<j dintro multime tip A={1,2,3,..n},astfel incat (a[i]+a[j])%k==0.
->daca (a[i]+a[j])%k==0 atunci ne dam seama de faptul ca a[i]%k+a[j]%k==0/k,adica suma resturilor sa fie 0 sau k.
->calculam resturile si numarul lor pentru elemtele multimii a,stocam valorile in fectorul de frecvente a.
->calculam numarul de perechi posibile:
a)perechi(0,0) si folosim formula combinari de a[0] luate cate 2
b)perechi(i,k-1)
c)perechi caz special pt k%2==0, perechi(k/2,k/2) daca e cazul
*/
int main(void)
{
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("Help_Mike.in","r");//deschidem fisiere
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier de intrare\n");
        exit(-1);
    }
    gis=fopen("Help_Mike.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschidere fisier de iesire\n");
        exit(-1);
    }
    int T=0;
    fscanf(fis,"%d",&T);//citim numarul de intrebari din fiser
    while(T!=0)
    {
        fprintf(gis,"%ld\n",Help_Mike(fis));//dam raspuns pentru fiecare intrebare
        T--;
    }
    fclose(fis);//inchidem fisiere
    fclose(gis);

    return 0;
}