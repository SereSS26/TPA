#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f5(int n,int i)
{   
    if(n==0)
        return n;
    else
        return pow(16,i)*(n%10)+f5(n/10,i+1);//folosim formula din exemplu
}
/*
int f5(int n)//aceeasi functie dar fara parametrul i care tine minte exponentul puterii 
{
    if(n==0)
        return 0;
    else 
    {
        int ultima_cifra=n%10;
        int val_hex_cifra_curenta=ultima_cifra+16*f5(n/10);
        return val_hex_cifra_curenta;
    }
}
*/
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;//fisiere
    int n=0,i=0;
    fis=fopen("5.in","r");
    if(fis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    gis=fopen("5.out","w");
    if(gis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    fscanf(fis,"%d",&n);//citire numar
    fprintf(gis,"%d\n",f5(n,i));
    fclose(fis);//inchidere fisiere
    fclose(gis);

    return 0;
}