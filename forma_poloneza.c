#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 100
//am ales in mod arbitrar dimensiunea initiala a vectorilor sa fie de 100 de elemente
int prioritate(int8_t a)//functie pentru a vedea prioritatea efectuarii operatiilor
{
    if(a=='+'||a=='-')
        return 2;
    if(a=='*'||a=='/')//inmultirea/impartirea au prioriate in fata adunarii/scaderii
        return 1;
    if(a=='('||a==')')//parantezele vor fi excluse din forma poloneza obtinuta
        return 3;
    return 0;
}
void push(int8_t *st,int8_t a,int *m)//functie pentru intrunctiunea push a stivei
{
    (*m)++;
    st[(*m)-1]=a;
}
int8_t peek(int8_t *st,int m)//functie pentru intructiunea peek a stivei
{
    return st[m-1];
}
int8_t pop(int8_t *st,int *m)//functie pentru intructiunea pop a stivei
{
    (*m)--;
    return st[(*m)];
}
int8_t gol(int m)//functie de verificare daca stiva este goala/sau nu
{
    if(m==0)
        return 0;
    else
        return 1;
}
void realocare_fp(int8_t **fp,int n)//functie pentru marire dimeniune fp(daca e cazul)
{   
    int8_t *fp2=NULL;
    fp2=(int8_t*)realloc(*fp,(n+1+SIZE)*sizeof(int8_t));
    if(fp2==NULL)
    {
        perror("eroare la alocarea memoriei\n");
        free(fp);
        exit(-1);
    }
    *fp=fp2;
}
void realocare_st(int8_t **st,int m)//functie pentru marire dimeniune stiva(daca e cazul)
{   
    int8_t *st2=NULL;
    st2=(int8_t*)realloc(*st,(m+1+SIZE)*sizeof(int8_t));
    if(st2==NULL)
    {
        perror("eroare la alocarea memoriei\n");
        free(st);
        exit(-1);
    }
    *st=st2;
}
//OBS!!!
/*
Deoarece vectorii st si fp sunt uint8_t,nu vom putea introduce/depasii intervalul [-128,127],
daca dorim efectuarea unui calcul cu numere mari putem modifica dimeniunea din int8_t in int32_t pt fp si st,
dar pentru exemplele din curs care au numere mici merge.
*/
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("forma_poloneza.in","r");//fisier de intrare
    if(fis==NULL)//verific deschidere fisier intrare
    {
        perror("eroare la deschidere fisier intrare\n");
    }
    gis=fopen("forma_poloneza.out","w");//fisier de iesire
    if(gis==NULL)//verific deschidere fisier iesire
    {
        perror("eroare la deschidere fisier iesire\n");
        exit(-1);
    }
    int8_t *st=NULL,*fp=NULL;//vectori dinamici pentru forma poloneza(fp) si stiva(st)
    st=(int8_t*)malloc(SIZE*sizeof(int8_t));
    if(st==NULL)
    {
        perror("eroare la alocare dinamica a memoriei\n");
        exit(-1);
    }
    fp=(int8_t*)malloc(SIZE*sizeof(int8_t));
    if(fp==NULL)
    {
        perror("eroare la alocarea dinamica a memoriei\n");
        exit(-1);
    }
    int n=0,m=0;
    int8_t a=0;
    while(fscanf(fis,"%c",&a)==1&&a!='\n')//citim expresia in forma normala din fisierul de intrare
    {
        if(isalpha(a))//daca gasim un operand(o litera) o adugam in fp
        {   
            if((n+1)%SIZE==0)//daca fp se umple ii marim dimenisiunea
            {
                realocare_fp(&fp,n);
            }
            fp[n]=a;
            fprintf(gis,"%c",fp[n]);
            n++;
        }
        else //altfel este un operator ce poate fi:(+ sau -),(* sau /),(paranteze)
        {
            if(a=='(')//cand dam de paranteza deschisa '(' o introducem in stiva
            {   
                if((m+1)%SIZE==0)//daca stiva se umple ii marim dimeniusnea
                {
                    realocare_st(&st,m);
                }
                push(st,a,&m);
                continue;
            }
            if(a!='('&&a!=')')//daca operatorul nu este paranteza avem urmatoarele situatii:
            {
                if(gol(m)==0)//daca stiva este goala il adaugam in stiva
                {
                    push(st,a,&m);
                }
                else
                {   
                    if(prioritate(a)<prioritate(peek(st,m)))//daca prioritatea nu incurca,atunci aduagam in stiva
                    {   
                        if((m+1)%SIZE==0)
                        {
                            realocare_st(&st,m);
                        }
                        push(st,a,&m);
                    }
                    else//daca pe stiva este deja un operator cu prioritate mai mare sau egala,atunci il scoatem de pe stiva,il punem in fp si punem in stiva pe a
                    {       
                        if((n+1)%SIZE==0)
                        {
                            realocare_fp(&fp,n);
                        }
                        //ex: daca pe stiva avem * si adugam +,atunci scoatem din stiva pe *
                        //ex: daca pe stiva avem * si adugam /,atunci scoatem din stiva pe *
                        fp[n]=pop(st,&m);
                        fprintf(gis,"%c",fp[n]);
                        n++;
                        push(st,a,&m);
                    }
                }
            }
            if(a==')')//cand dam de paranteza inchisa ')',luam tot de pe stiva pana dam de paranteza cealalta '('
            {       
                while(a!='(')
                {       
                    if(gol(m)==1)
                        a=pop(st,&m);
                    if(a=='(')
                        break;
                    if(gol(m)==0)
                        break;
                    if((n+1)%SIZE==0)
                    {
                        realocare_fp(&fp,n);
                    }
                    fp[n]=a;
                    fprintf(gis,"%c",fp[n]);
                    n++;
                }
            }
        }
    }
    while(gol(m)==1)//la final scoatem toate elementele ramase pe stiva si le adugam si pe acestea in fp
    {   
        if((n+1)%SIZE==0)
        {
            realocare_fp(&fp,n);
        }
        fp[n]=pop(st,&m);
        fprintf(gis,"%c",fp[n]);
        n++;
    }
    fprintf(gis,"\n");
    for(int i=0;i<n;i++)
    {
        printf("%c",fp[i]);
    }
    printf("\n");
    int nr=0,x=0,y=0;
    for(int i=0;i<n;i++)//calcul pentru valoare expresie
    {
        if(isalpha(fp[i]))//daca dam de un operand(litera/numar) ii dam o valoare din fisier si adaugam pe stiva
        {   
            if((m+1)%SIZE==0)
            {
                realocare_st(&st,m);
            }
            fscanf(fis,"%d",&nr);
            push(st,nr,&m);
        }
        else//cand dam de un operator luam doua valori numerice de pe stiva si facem operatia respectiva
        {   
            if((m+1)%SIZE==0)
            {
                realocare_st(&st,m);
            }
            x=pop(st,&m);
            y=pop(st,&m);
            //rezultatul obtinut va fi practic tot un operand si il introducem pe stiva pentru a face calculul mai departe
            if(fp[i]=='+')
            {       
                //printf("%d\n",y+x);
                push(st,y+x,&m);
            }
            if(fp[i]=='-')
            {   
                //printf("%d\n",y-x);
                push(st,y-x,&m);
            }
            if(fp[i]=='*')
            {   
                //printf("%d\n",y*x);
                push(st,y*x,&m);
            } 
            if(fp[i]=='/')
            {   
                //printf("%d\n",y/x);
                push(st,y/x,&m);
            }  
        }
    }
    nr=pop(st,&m);//ultimul numar ramas in stiva este chiar valoarea expresiei aritmetica
    printf("%d\n",nr);
    fprintf(gis,"%d\n",nr);
    fclose(fis);//inchidem fisiere
    fclose(gis);
    free(fp);//eliberam memoria alocata dinamic
    free(st);

    return 0;
}