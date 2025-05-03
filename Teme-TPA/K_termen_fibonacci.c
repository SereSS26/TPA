#include <stdio.h>
#include <stdlib.h>
#define MO 666013

void Ridicare_Putere1(long long int A[1][2],long long int B[2][2])//functie pentru inmultirea a doua matrici una de 1x2,cealalta de 2x2
{
    long long int C[1][2],i=0,j=0;//matricea rezultata va fi de 1x2
    for(i=0;i<2;i++)
    {
        C[0][i]=0;//la inceput matricea C e nula, in ea vom face inmultirea
        for(j=0;j<2;j++)
        {
            C[0][i]=(C[0][i]+A[0][j]*B[j][i])%MO;//inmultirea normala pentru matrici
        }
    }
    for(i=0;i<2;i++)
    {
        A[0][i]=C[0][i];//actualizam matricea A,defapt pe M din functia princpipala
    }
}
void Ridicare_Putere2(long long int A[2][2],long long int B[2][2])//functie de inmultire a doua matrici ambele de 2x2
{
    long long int C[2][2],i=0,j=0,k=0;//matricea rezultat va fi de 2x2
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            C[i][j]=0;//la inceput matricea C va fi nula,in ea vom face inmultirea
            for(k=0;k<2;k++)
            {
                C[i][j]=(C[i][j]+A[i][k]*B[k][j])%MO;//inmultire de matrici propiu-zisa
            }
        }
    }
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            A[i][j]=C[i][j];//actualizam matricea A,defapt pe Z din functia principala
        }
    }
}
void kfib(FILE *fis,FILE *gis)
{
    long long int Z[2][2],M[1][2],k=0;//Z->o matrice de 2x2 constanta cu semificatia din indicatile problemei,M->matrice de 1x2 formata din doi termeni ai sirului lui fibbonacci
    fscanf(fis,"%lld",&k);//k->numarul ce se da in fisier,al catalea termen al sirului lui fibbonacci vrem sa gasim
    Z[0][0]=0;//matricea Z va fi constanta cu valorile (0 1;1 1)
    Z[0][1]=1;
    Z[1][0]=1;
    Z[1][1]=1;
    M[0][0]=0;//la inceput matricea M contine primii doi termeni ai sirului lui fibbonacii adica (0 1)
    M[0][1]=1;
    while(k!=0)//aplicam algorimul din curs pentru ridicare la putere cu complexitate O(log k)
    {
        if(k%2!=0)
        {
            Ridicare_Putere1(M,Z);//functie de inmultire a doua matrici una de 1x2,cealalta de 2x2
        }
        Ridicare_Putere2(Z,Z);//functie de inmultire a doua matrici ambele de 2x2
        k=k/2;
    }
    fprintf(gis,"%lld\n",M[0][0]);//scriem solutia in fisier care se afla pe pozitia din coltul din stanga sus a lui M dupa calcul
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("kfib.in","r");//deschidem fisiere
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului de intrare\n");
        exit(-1);
    }
    gis=fopen("kfib.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului de iesire\n");
        exit(-1);
    }
    kfib(fis,gis);//rezolvare
    fclose(fis);//inchidem fisiere
    fclose(gis);

    return 0;
}