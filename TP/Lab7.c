#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct elem
{
    int info;
    struct elem *urm;
}elem;
elem *nou(elem *list,int n)
{
    elem *e=NULL;
    e=(elem*)malloc(1*sizeof(elem));
    if(e==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    e->info=n;
    e->urm=list;
    return e;
}
elem *adaug_inceput(elem *list,int n)
{
    return nou(list,n);
}
void afisare(elem *list)
{
    while(list!=NULL)
    {
        printf("%d ",list->info);
        list=list->urm;
    }
    printf("\n");
}
void eliberare(elem *list)
{
    elem *p=NULL;
    while(list!=NULL)
    {
        p=list->urm;
        free(p);
        list=p;
    }
}
void inversare(elem **list)
{
    elem *anterior=NULL;
    elem *curent=*list;
    elem *urmator=NULL;
    if(curent==NULL)
        return;
    if(curent->urm==NULL)
        return;
    while(curent!=NULL)
    {
        urmator=curent->urm;
        curent->urm=anterior;
        anterior=curent;
        curent=urmator;
    }
    *list=anterior;
}
void sterge_inceput(elem **list)
{   
    elem *p=*list;
    if(p==NULL)
        return;
    else
    {
        p=*list;
        *list=p->urm;
        free(p);
    }
}
void sterge_final(elem **list)
{
    elem *p=NULL;
    elem *anterior=NULL;
    p=*list;
    while(p->urm->urm!=NULL)
    {
        p=p->urm;
    }
    anterior=p;
    p=p->urm;
    anterior->urm=NULL;
    free(p);
    *list=anterior;
}
void sterge_element(elem **list,int n)
{
    elem *p=NULL;
    elem *anterior=NULL;
    p=*list;
    anterior=p;
    if(p->info==n)
    {   
        sterge_inceput(&p);
        return;
    }
    while(p!=NULL&&p->info!=n)
    {   
        anterior=p;
        p=p->urm;
    }
    anterior->urm=p->urm;
    free(p);
    *list=anterior;
}
void f7_1(FILE *fis,FILE *gis)
{
    elem *list1=NULL;
    int n=0,x=0;
    fscanf(fis,"%d",&n);
    while(n!=0)
    {
        fscanf(fis,"%d",&x);
        list1=adaug_inceput(list1,x);
        n--;
    }
    afisare(list1);
    inversare(&list1);
    sterge_inceput(&list1);
    sterge_final(&list1);
    list1=adaug_inceput(list1,1);
    list1=adaug_inceput(list1,3);
    list1=adaug_inceput(list1,4);
    list1=adaug_inceput(list1,6);
    list1=adaug_inceput(list1,7);
    afisare(list1);
    sterge_element(&list1,4);
    afisare(list1);
    eliberare(list1);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Lab7.in","r");
    if(fis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    gis=fopen("Lab7.out","w");
    if(gis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    f7_1(fis,gis);
    fclose(fis);
    fclose(gis);
    return 0;
}