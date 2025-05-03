#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void afisare(int *tabla_sah,int n)//functie optionala de afisare pe ecran a unei solutii gasite
{   
    int linie=0,coloana=0;
    for(linie=0;linie<n;linie++) 
    {
        for(coloana=0;coloana<n;coloana++) 
        {
            if(tabla_sah[linie]==coloana) 
            {
                printf("X ");//am marcat cu X dama
            } 
            else 
            {
                printf("0 ");//am marcat cu 0 spatiul gol
            }
        }
        printf("\n");
    }
    printf("\n");
}
int solutie(int n,int coloana)
{
    if(n==coloana)
        return 1;
    else
        return 0;
}
int valid(int *tabla_sah,int linie, int coloana) //functie de validare a posibilitatii amplasarii unei dame pe respectiva coloana
{   
    int poz=0;
    for(poz=0;poz<linie;poz++) 
    {
        if(tabla_sah[poz]==coloana||abs(tabla_sah[poz]-coloana)==abs(poz-linie))//conditia care trebuie respectata(o dama poate ataca pe orizontala,verticala,dar si pe diagoanala princpila si secundara)
        {
            return 0;
        }
    }
    return 1;
}
/*
tabla de sah poate fi un vector,nu o matrice!!!
indicii vectorului vor reprezenta liniile matrcii,iar valorile coloanele
*/
void dame(int coloana,int n,int *tabla_sah,int *nr)
{   
    int linie=0;
    for(linie=0;linie<n;linie++)//algorimt de backtraking construit dupa exemplul din curs
    {   
        tabla_sah[coloana]=linie; 
        if(valid(tabla_sah,coloana,linie))//verificam daca putem plasa dama pe respectiva pozitie prin functia valid care returneaza 1 daca e posbil sau 0 daca nu este posibil
        {           
            if(solutie(coloana+1,n))//functie de validare a solutiei
            {   
                (*nr)++;//mareste numarul de solutii gasite
                afisare(tabla_sah,n);//am gasit o solutie putem sa o printam pe ecran daca dorim sa vedem cum arata
            }
            else
                dame(coloana+1,n,tabla_sah,nr);//apeleaza functia recursiva pentru a plasa o dama pe urmatoarea coloana
        }
    }
}
int main(void)
{       
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("regine.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschidere fisier de intrare\n");
        exit(-1);
    }
    gis=fopen("regine.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierlui de iesire\n");
        exit(-1);
    }
    int n=0,nr=0;//n-numarul de patrate de pe o linie/coloana a tablei de sah,nr-numarul de moduri in care putem rezolva problema reginelor
    fscanf(fis,"%d",&n);
    int *tabla_sah=NULL;
    tabla_sah=(int*)malloc((n)*sizeof(int));//tabla de sah alocata dinamic ca UN VECTOR(nu ca o matrice)!!! deoarece putem stoca indicii coloanelor ca vlorile fiecarui element din vector.
    if(tabla_sah==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    memset(tabla_sah,-1,n*sizeof(int));//initializam tabla de sah cu toate elemtele -1 deoarece la inceput nu avem plasata nicio dama pe tablas
    dame(0,n,tabla_sah,&nr);//apelam functia de generare a solutiilor
    free(tabla_sah);//eliberam memoria alocata dinamic
    fprintf(gis,"%d\n",nr);//scriem in fiser numarul de moduri in care se poate rezolva problema
    fclose(fis);//inchidem fisierul de intrare
    fclose(gis);//inchidem fiserul de iesire

    return 0;
}