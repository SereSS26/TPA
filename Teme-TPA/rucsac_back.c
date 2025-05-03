#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NMAX 15

typedef struct
{
    int w;//greutatea
    int p;//pretul
}Obiect;//acum am stocat pretul si greutatea obiectelor intr-o structura
void back(Obiect *obiect,int n,int g,int i,int cw,int cp,int *sol)
{
    if(i==n||cw==g)//conditie de oprire(am parcurs obiectele sau am atins capacitatea maxima)
    {
        if(cp>*sol)//actualizam solutia daca este cazul
        {
            *sol=cp;
        }
        return;
    }
    if(cw+obiect[i].w<=g)//daca adaugarea unui obiect nu depaseste capacitatea maxima,atunci...
    {
        back(obiect,n,g,i+1,cw+obiect[i].w,cp+obiect[i].p,sol);//adaugam obiectul curent si continuam
    }
    back(obiect,n,g,i+1,cw,cp,sol);//continuam cu urmatorul obiect
}
void rucsac_back(FILE *fis,FILE *gis)
{   
    Obiect *obiect=NULL;
    int n=0,g=0,i=0,sol=0;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&g);
    obiect=(Obiect*)malloc(n*sizeof(Obiect));//strctura dinamica pentru greutati si preturi ale fiecarui obiect
    if(obiect==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%d",&obiect[i].w);//citim datele din fisier
        fscanf(fis,"%d",&obiect[i].p);
    }
    back(obiect,n,g,0,0,0,&sol);//rezolvare
    fprintf(gis,"%d\n",sol);//scriem solutia in fisier
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
    rucsac_back(fis,gis);//rezolvare cu backtraking
    fclose(fis);//inchidem fisiere
    fclose(gis);
    clock_t end=clock();//gata timp
    double timp=(double)(end-start)/CLOCKS_PER_SEC;
    printf("%lf\n",timp);//timp de executie
    //ar mai trebui facut grafic pentru a vedea cresterea timpului pentru n<=15...

    return 0;
}