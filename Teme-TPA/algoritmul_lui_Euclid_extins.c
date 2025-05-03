#include <stdio.h>
#include <stdlib.h>

void euclid_extins(int a,int b,int *s,int *x,int *y)//algoritm euclid extins varinata recursiva
{
    int x1=0,y1=0;//variabile pentru a stoca valorile intermediare
    if(b==0)//daca b este 0,atunci a este cmmdc automat
    {
        *s=a;
        *x=1;
        *y=0;
    }
    else
    {
        euclid_extins(b,a%b,s,&x1,&y1);//apelare recursiva
        *x=y1;
        *y=x1-(a/b)*y1;
    }
}
void citire(FILE *fis,FILE *gis)
{
    int t=0,a=0,b=0,c=0,i=0;
    fscanf(fis,"%d",&t);//t->numarul de ecuatii care se da
    for(i=0;i<t;i++)
    {
        fscanf(fis,"%d",&a);//citim din fisier coeficintii din ecutaie
        fscanf(fis,"%d",&b);
        fscanf(fis,"%d",&c);
        int s=0,x=0,y=0;//s->va fi cmmdc a lui a si b,iar x si y vor fi solutile ecuatiei
        euclid_extins(a,b,&s,&x,&y);//functie pentru algorimul lui euclid extins varianta recursiva
        if(c%s!=0)
            fprintf(gis,"0 0\n");//daca ecuatia nu are solutie scriem 0 0 in fisier
        else
            fprintf(gis,"%d %d\n",(c/s*x),(c/s*y));
    }
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    fis=fopen("euclid3.in","r");//deschidem fisierele
    if(fis==NULL)
    {
        perror("eroare la deschiderea fisierului de intrare\n");
        exit(-1);
    }
    gis=fopen("euclid3.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului de iesire\n");
        exit(-1);
    }
    citire(fis,gis);//functie de citire a datelor
    fclose(fis);//inchidem fisierele
    fclose(gis);

    return 0;
}