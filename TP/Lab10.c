#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int f10_1(int a,int b)
{
    if(b==0)
        return a;
    else
        return f10_1(b,a%b);
}
void f10_1_citire(FILE *fis,FILE *gis)
{
    int a=0,b=0,r=0;
    fscanf(fis,"%d",&a);
    fscanf(fis,"%d",&b);
    r=f10_1(a,b);
    fprintf(gis,"%d\n",r);
}
int f10_2(int n)
{
    if(n<10)
        return n;
    else
        return n%10+f10_2(n/10);
}
void f10_2_citire(FILE *fis,FILE *gis)
{
    int n=0,r=0;
    fscanf(fis,"%d",&n);
    r=f10_2(n);
    fprintf(gis,"%d\n",r);
}
int f10_3(int n,int c)
{
    if(n==0)
        return c;
    else
    {
        if(n%10>c)
            return f10_3(n/10,n%10);
        else
            return f10_3(n/10,c);
    }
}
void f10_3_citire(FILE *fis,FILE *gis)
{
    int n=0,c=0;
    fscanf(fis,"%d",&n);
    c=f10_3(n,c);
    fprintf(gis,"%d\n",c);
}
int f10_4(int n)
{
    if(n==0||n==1)
        return 1;
    else
    {
        return f10_4(n-1)+f10_4(n-2);
    }
}
void f10_4_citire(FILE *fis,FILE *gis)
{
    int n=0,r=0;
    fscanf(fis,"%d",&n);
    r=f10_4(n);
    fprintf(gis,"%d\n",r);
}
char f10_5(char *s1,char *s2,int n)
{
    return 0;
}
void f10_5_citire(FILE *fis,FILE *gis)
{
    char s1[200],s2[200],r;
    int n=0;
    fscanf(fis,"%199s",s1);
    fscanf(fis,"%199s",s2);
    fscanf(fis,"%d",&n);
    r=f10_5(s1,s2,n);
    printf("%c\n",r);
}
int main(void)
{   
    FILE *fis=NULL,*gis=NULL;
    fis=fopen("Lab10.in","r");
    if(fis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    gis=fopen("Lab10.out","w");
    if(gis==NULL)
    {
        perror("eroare\n");
        exit(-1);
    }
    f10_1_citire(fis,gis);
    f10_2_citire(fis,gis);
    f10_3_citire(fis,gis);
    f10_4_citire(fis,gis);
    ///f10_5_citire(fis,gis);
    fclose(fis);
    fclose(gis);

    return 0;
}