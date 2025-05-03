#include <stdio.h>
#include <stdlib.h>

int putere_doi_ko(int n)
{   
    n=n|(n>>1);
    n=n|(n>>2);
    n=n|(n>>4);
    n=n|(n>>8);
    n=n|(n>>16);
    return n+1;
}
int putere_doi_ok(int n)
{
    if((n&(n-1))==0)
        return 1;
    else
        return 0;
}
int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
void build_tree(int *tree,int *v,int nod,int stanga,int dreapta)
{   
    int mid=0;
    if(stanga==dreapta)
    {
        tree[nod]=v[stanga]; 
        return;
    }
    mid=(stanga+dreapta)/2;
    build_tree(tree,v,2*nod+1,stanga,mid);
    build_tree(tree,v,2*nod+2,mid+1,dreapta);
    tree[nod]=max(tree[2*nod+1],tree[2*nod+2]);
}
void modifica_tree(int *tree,int *v,int nod,int stanga,int dreapta,int a,int b)
{
    int mid=0;
    if(stanga==dreapta)
    {
        tree[nod]=b;
        return;
    }
    mid=(stanga+dreapta)/2;
    if(a<=mid)
    {   
        modifica_tree(tree,v,2*nod+1,stanga,mid,a,b);
    }
    else
    {   
        modifica_tree(tree,v,2*nod+2,mid+1,dreapta,a,b);
    }
    tree[nod]=max(tree[2*nod+1],tree[2*nod+2]);
}
void rezolvare(int *tree,int *v,int nod,int stanga,int dreapta,int a,int b,int *maxi)
{   
    int mid=0;
    if(stanga>b||dreapta<a)
        return;
    if(stanga>=a&&dreapta<=b)
    {
        *maxi=max(*maxi,tree[nod]);
        return;
    }
    mid=(stanga+dreapta)/2;
    rezolvare(tree,v,2*nod+1,stanga,mid,a,b,maxi);
    rezolvare(tree,v,2*nod+2,mid+1,dreapta,a,b,maxi);
}
void citire(FILE *fis,FILE *gis)
{
    int n=0,m=0,i=0,x=0,a=0,b=0,dimensiune=0,maxi=0;
    int *v=NULL,*tree=NULL;
    fscanf(fis,"%d",&n);
    fscanf(fis,"%d",&m);
    v=(int*)malloc(n*sizeof(int));
    if(v==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    for(i=0;i<n;i++)
    {
        fscanf(fis,"%d",&v[i]);
    }
    if(putere_doi_ok(n)==1)
    {
        dimensiune=n*2-1;
    }
    else
    {
        dimensiune=putere_doi_ko(n)*2-1;
    }
    tree=(int*)malloc(dimensiune*sizeof(int));
    if(tree==NULL)
    {
        perror("eroare la alocarea dinamica\n");
        exit(-1);
    }
    build_tree(tree,v,0,0,n-1);
    while(m!=0)
    {   
        fscanf(fis,"%d",&x);
        fscanf(fis,"%d",&a);
        fscanf(fis,"%d",&b);
        if(x==0)
        {
            maxi=0;
            rezolvare(tree,v,0,0,n-1,a-1,b-1,&maxi);
            fprintf(gis,"%d\n",maxi);
        }
        if(x==1)
        {   
            modifica_tree(tree,v,0,0,n-1,a-1,b);
        }
        m--;
    }
    free(tree);
    free(v);
}
int main(void)
{
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("arbint.in","r");
    if(fis==NULL)
    {
        perror("eroare la deschiderea fiserului de intrare\n");
        exit(-1);
    }
    gis=fopen("arbint.out","w");
    if(gis==NULL)
    {
        perror("eroare la deschiderea fisierului de iesire\n");
        exit(-1);
    }
    citire(fis,gis);
    fclose(fis);
    fclose(gis);

    return 0;
}